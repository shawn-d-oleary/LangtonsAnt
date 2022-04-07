namespace Models
{
    public class Square
    {
        public int X { get; set; }
        public int Y { get; set; }
        public bool IsWhite { get; set; }
        Square() { }
        public Square(int x, int y)
        {
            this.X = x;
            this.Y = y;
            this.IsWhite = true;
        }
        public Square(int x, int y, bool isWhite = true)
        {
            this.X = x;
            this.Y = y;
            this.IsWhite = isWhite;
        }
    }
}
