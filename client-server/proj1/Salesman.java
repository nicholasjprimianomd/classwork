import java.util.*;

/**
 * Salesman.Java
 * 
 *<p><b>Project 1 : Willy Loman's Revenge</b> 
 *
 * <p>This program produces an invoice for a salesman's order. The
 * salesman provides (as input) the number sold for each item.
 * The program produces an invoice that gives the number sold, unit
 * price, and extended amount for each item, as well as a grand
 * total.</p>
 *
 *
 * @author <a href="mailto:nprimiano@fordham.edu">Nicholas Primiano</a>
 * @version 1.0 27 January 2014
 */
    
public class Salesman {
    public static void main(String[] args) {
        int[] amounts = inputAmounts(Item.getNames());
        double[] total = calcExtended(amounts, Item.getPrices());
        printTotals(Item.getNames(), amounts, Item.getPrices(),total);
    }

    /**
     * Get number of each item sold from the user using the Scanner class
     * 
     * @param <code>names</code> of items
     * @return <code>amounts</code> of each item sold
     */
    
   public static int[] inputAmounts(String[] names) {
        Scanner scan = new Scanner(System.in);
        int[] amounts = new int [names.length];    
        System.out.println("Enter the number sold for each item:\n");
        for (int i = 0; i < names.length; i++) {
            System.out.print(names[i] + "? ");
            amounts[i] = scan.nextInt();
        }
        scan.close();
        System.out.println("\n");
        return amounts;
    }

    /**
     * Calculate extended amounts of each item sold 
     * 
     * @param <cod>amounts</code> of each item sold
     * @param <code>prices</code> of each item
     * @return <code>total</code> of each extended amount
     */
    
   public static double[] calcExtended(int[] amounts, double[] prices) {
        double[] total = new double[amounts.length];
        for ( int i = 0; i < prices.length; i++) {
            total[i] = amounts[i] * prices[i];            
        }
        return total;
    }

    /**
     * Calculate grand total of items sold
     * 
     * @param <code>total</code> number of each item sold
     * @return <code>sum</code> of all items sold
     */
    
    public static double caclGrandTotal(double[] total) {
        double sum = 0;
        for(int i = 0; i < total.length; i++) {
            sum += total[i];
        }
        return sum;
    }
    
    /**
     * Print names, amounts, and princes of each item.
     * As well as the grand total.
     * 
     * @param <code>names</code> of each item
     * @param <code>amounts</code> of each item sold
     * @param <code>prices</code> for each item
     * @param <code>total</code> number of items sold
     */
    
    public static void printTotals(String[] names, 
				   int[] amounts, double[] prices, double[] total) {
        System.out.println(String.format("%-11s %15s %11s %10s",
					 "Item", "Unit", "Number", "Extended"));
        System.out.println(String.format("%28s %9s %10s", 
					 "Price", "Sold", "Amount"));
        System.out.println("--------------------------" +
			   "-------------------------");
        for (int i = 0; i < prices.length; i++) {
                System.out.println(String.format("%-18s %10.2f %10d %10.2f",
				   names[i],  prices[i],  amounts[i],  total[i]));
        }
        System.out.println(String.format("\nOrder grand total: $%.2f", 
					 caclGrandTotal(total)));    
    }
}


