#include <bjarne/std_lib_facilities.h>
class lounge{
public:
  lounge(int seats, int tables) {
    set_seats(seats);
    set_tables(tables);}
  int get_seats(){
    return seats;}
  void set_seats(int set){
       seats = set;}
  void set_tables(int set){
       tables = set;}
  int get_tables(){
    return tables;}
private:
  int seats;
  int tables;};		        
ostream& operator<<(ostream& lounge_output, lounge& second_floor);
int main(){
  lounge second_floor(1, 4);
  //main}
ostream& operator<<(ostream& lounge_output, lounge& second_floor){
  lounge_output << second_floor.get_seats() << second_floor.get_tables() << endl
  return lounge_output;}



int main(){
   cout << "Enter the input file name: ";
   string file_name;
   cin >> file_name;
   ifstream ifs(file_name.c_str());  //use ofstream to wrtie to a file
   if (!ifs) error("Couldn't open file ", file_name);
   int line_count = 0;
   string s;
   while (getline(ifs, s)) //ifs >> Var -to write to a file
      line_count++;
   cout << file_name << ": " << line_count << " lines\n";}
Ex. Operator Overload
istream&  operator>>(istream& input, Name_pair& np){
    input >> np.name;
    input >> np.age;
    return input;}
bool operator==(const Name_pair& np0, const Name_pair& np1){
    if((np0.name == np1.name) && (np0.age == np1.age))
	return true;
    else 
	return false;}
bool operator!=(const Name_pair& np0, const Name_pair& np1){
    if((np0.name != np1.name) || (np0.age != np1.age))
	return true;
    else 
      return false;}
bool operator<(const Name_pair& np0, const Name_pair& np1){
    if(np0.name < np1.name)
	return true;
    else
	return false;}
