

import javax.swing.JFrame;

///////////////////////////////////////////// class SlidePuzzle
class SlidePuzzle {
    //============================================= method main
    public static void main(String[] args) {
        JFrame window = new JFrame("Puzzle");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setContentPane(new SlidePuzzleGUI());
        window.pack();  // finalize layout
        window.setVisible(true);  // make window visible
       // window.setResizable(false);
    }//end main
}//endclass SlidePuzzle
