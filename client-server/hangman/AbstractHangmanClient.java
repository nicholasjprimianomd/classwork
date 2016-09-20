import java.net.*;
import java.io.*;

/**
 * <p>This class contains the logic of a hangman game.</p>
 *
 * <p><a id="intro"></a>Since this class is a derived class of
 * <code>SimpleSocketClient</code>, the main action is in 
 * its <code>handleSession()</code> method. Said method will contact a
 * Hangman server, and obtain a word from the server. It will then
 * interact with the player, until one of two things has happened:</p>
 * <ul>
 *   <li>The player has guessed the word. In this case, the player is
 *       congratulated.</li>
 *   <li>The player has made too many bad guesses. In this case, the player is
 *      "punished". </li>
 * </ul>
 * <p>Those methods that actually interact with the player are left as
 * abstract methods. A concrete subclass of 
 * <code>AbstractHangmanClient</code> can then interact with the
 * player as it sees fit. Hence, one might have a
 * text-based interface, a graphical interface, perhaps even an audio 
 * interface.</p> 
 * 
 * @author Nicholas Primiano
 * @version 2.0, 8 May 2014
 */

public abstract class AbstractHangmanClient extends SimpleSocketClient 
{
  
  /**
   * State control value for unconnected state
   */
  private final static int STATE_UNCONNECTED = 1;

 /**
   * State control value for connected state
   */  
  private final static int STATE_CONNECTED = 2;

  /**
   * State control value for playing state
   */  
  private final static int STATE_PLAYING = 3;

  /**
   * State control value for winner state
   */  
  private final static int STATE_WINNER = 4;

  /**
   * State control value for loser state
   */  
  private final static int STATE_LOSER = 5;

  /**
   * State control variable
   */  
  protected static int state;

  /**
   * the default host on which a Hangman server is running
   */
  protected static final String HANGMAN_DEFAULT_SERVER = "erdos.dsm.fordham.edu";

  /**
   * the default Hangman port number
   */
  protected static final int HANGMAN_DEFAULT_PORT = 9999;   

  /**
   * total number of guesses remaining
   */
  protected int guessesRemaining;

  /**
   * the word as determined so far by the player's letter choices
   */
  protected StringBuffer wordsSoFar;

  /**
   * correct word to display to the player
   */
  protected String correct;

  /**
   * the word to be guessed by the player
   */
  protected String theWord;

  /**
   * current guessed character
   */
  protected int correctGuess;

  private DataInputStream remoteDIS;
  private InputStreamReader remoteISR;
  private SafeBufferedReader remoteBR;

  private final int TOTAL_GUESSES_REMAINING = 10;
  private char curGuess;
  private int length;  
 
  /**
   * Congratulate the winner on her acumen.
   */
  public abstract void congratulateWinner();
  
  /**
   * Display the current game state.
   */
  public abstract void displayGame();

  /**
   * Obtain a guess from the user.
   *
   * @return obtain an uppercase letter for a GUESS
   */
  public abstract char elicitGuess();
  
  /**
   * Find out whether we want to play again.
   *
   * @return true or false, according to whether we want to play again
   * or not.
   */
  public abstract boolean elicitPlayAgain();
  
  /**
   * Player didn't guess the word; hang her.
   */
  public abstract void punishLoser();  
 
  /**
   * The constructor for the <code>AbstractHangmanClient</code> class.
   * 
   * @param debugging True iff debugging output is enabled
   * @param hostName The host on which the hangman server resides
   * @param portNumber The port number on which the server is
   * listening
   */
  AbstractHangmanClient(boolean debugging, String hostName, int portNumber) 
  {
    super.debugOn = debugging;
    super.hostName = hostName;
    super.portNum = portNumber;
    super.run();
  }

  /**
   * <p>This methods overrides the SimpleSocketClient.handleSession()
   * method.</p>
   *
   * <p>As mentioned in the <a href="#intro">introductory section</a>, 
   * this method handles the main logic of a hangman game. It uses 
   * a fairly simple finite state machine to do this.</p>
   */
  public void handleSession() 
  {   
      try {
	      remoteDIS = new DataInputStream(remoteInputStream);
	      remoteISR = new InputStreamReader(remoteDIS);
	      remoteBR = new SafeBufferedReader(remoteISR);
	      // ignore welcome message
	      remoteBR.readLine();
	      remoteBR.readLine();
	      state = STATE_CONNECTED;
	      while(state != STATE_UNCONNECTED){
		switch(state) {
		case (STATE_UNCONNECTED):
		  break;
		case (STATE_CONNECTED):
		  startNewGame();
		  break;
		case (STATE_PLAYING):
		  curGuess = elicitGuess();
		  processGuess();
		  break;
		case (STATE_WINNER):
		  handleEndGame();
		  break;
		case (STATE_LOSER):
		  handleEndGame();
		  break;
		default:
		   state = STATE_UNCONNECTED;
		   break;
		}
      }
      remoteOutputStream.writeBytes("BYE" + "\n");
    } catch (IOException e) {
      e.printStackTrace();
    }
  } 
   
  /**
   * <p>Start a new game.</p>
   *
   * <p> This involves contacting the server, finding out the length of
   * the newword, initializing our guess for what the new word looks 
   * like, and displaying the letter.</p>
   */
  public void startNewGame()
  {
    try {
      remoteOutputStream.writeBytes("NEW" + "\n");
      String  wordLength;
      wordLength = remoteBR.readLine();
      length = Integer.parseInt(wordLength);
      guessesRemaining = TOTAL_GUESSES_REMAINING;
      correctGuess = 0;
      wordsSoFar = new StringBuffer();
      for (int i = 0 ; i < length; i ++){
	wordsSoFar.append('*');
      }
      displayGame();
      state = STATE_PLAYING;
    } catch (IOException e) {
      e.printStackTrace();
    }  
  }
  
  /**
   * <p>Process a valid (A..Z) guess from the player.</p>
   *
   * <p>We send the guess to the server. The server tells us at what
   * positions the guess matches the word. Our knowledge of the word 
   * is updated appropriately. If we have guessed the word, the player is 
   * congratulated. If there are no matches, the number of remaining
   * guesses is decremented, and the player is punished if there are no
   * remaining guesses.</p>
   */
  public void processGuess() 
  {
    try {
      remoteOutputStream.writeBytes("GUESS " + curGuess + "\n" );
      boolean corGuesses = false;
      for (int i = 0; i < length;  i++) {
	String s = remoteBR.readLine();
	// s is "true" or "false"
	if (Boolean.valueOf(s.trim()) && wordsSoFar.charAt(i) == '*') {
	  wordsSoFar.setCharAt(i, curGuess); 
	  corGuesses = true;
	  correctGuess++;
	}
      }
      if (!corGuesses) guessesRemaining--;
      if (guessesRemaining == 0 ) state = STATE_LOSER; else 
	if (correctGuess == length) state = STATE_WINNER; else {
	  displayGame();
	}
    } catch (IOException e) {
      e.printStackTrace();
    } 
  }
   
  /**
   * Handle the end of game (either a winner or a loser)
   */
  public void handleEndGame() 
  {
    try {
	remoteOutputStream.writeBytes("QUIT" + "\n");
	correct = remoteBR.readLine();
    if (state == STATE_WINNER) congratulateWinner();
    if (state == STATE_LOSER) punishLoser();
      } 
      catch (IOException e) {
	e.printStackTrace();
      }
    if (elicitPlayAgain()) 
      state = STATE_CONNECTED;  
    else 
      state = STATE_UNCONNECTED;
    
  }

}

