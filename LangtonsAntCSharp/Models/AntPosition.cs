namespace Models
{
    public class AntPosition
    {
        public int Id { get; set; }
        public int X { get; set; }
        public int Y { get; set; }
        public int Direction { get; set; }

        public AntPosition()
        {

        }

        public AntPosition(AntPosition ap)
        {
            this.Id = ap.Id;
            this.X = ap.X;  
            this.Y = ap.Y;
            this.Direction = ap.Direction;
        }

        public void Move(bool isWhite)
        {
            //increment Id
            this.Id++;

            //change Direction
            if (isWhite)
                this.Direction += 90;
            else
                this.Direction -= 90;

            if (this.Direction == 360)
                this.Direction = 0;
            if (this.Direction == -90)
                this.Direction += 360;
            
            //move forward one unit based on direction
            switch (this.Direction)
            {
                case 0:
                case 360:
                    this.Y += 1;
                    break;
                case 90:
                    this.X += 1;
                    break;
                case 180:
                    this.Y -= 1;
                    break;
                case 270:
                    this.X -= 1;
                    break;
                default:
                    break;
            }
        }
    }
}
