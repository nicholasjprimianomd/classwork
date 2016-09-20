public class Item {
  //private data memebers storing prices and names
    private static final double prices[] = {10.62, 14.89, 
	13.20, 16.50, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
    private static final String names[] = {"Toothpaste", "Fish sticks", 
        "Peanut butter", "Zinc bushing", "Axolotl", "Shoe polish", "Green eggs", 
        "Filets of mulberry", "Doughnut molds", "Cadmium syrup"};
    
    /**
     * Get method for item prices
     * 
     * @return prices
     */
   public static final double[] getPrices() {
        return prices;
    }
    
    /**
     * Get method for item names
     * 
     * @return names
     */
   public static final String[] getNames() {            
        return names;
    }
}
