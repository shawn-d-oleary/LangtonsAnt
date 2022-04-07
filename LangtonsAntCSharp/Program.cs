using Models;
using System.Text.Json;

Console.WriteLine("Langtons Ant. How many moves (K) would you like? ");

string inputK = Console.ReadLine() ?? String.Empty;

int K = 0;
var success = int.TryParse(inputK, out K);

if (!success){
    Console.WriteLine("Invalid input.\n");
    return;
}

Console.WriteLine($"K = {K}\n");

//squares (the grid)
List<Square> squares = new List<Square>();
squares.Insert(0, new Square(0, 0));

//initial ant position
AntPosition currentAntPosition = new AntPosition { Id = 0, X = 0, Y = 0, Direction = 90 }; 

//list of ant positions (based on moves)
List<AntPosition> antPositions = new List<AntPosition>();

//insert intital ant position into list
antPositions.Insert(0, new AntPosition(currentAntPosition));

for (int i = 1; i <= K; i++)
{
    var square = squares.SingleOrDefault(s => s.X == currentAntPosition.X && s.Y == currentAntPosition.Y);
        
    if (square == null) {
        square = new Square(currentAntPosition.X, currentAntPosition.Y);
    }

    currentAntPosition.Move(square.IsWhite);

    //flip position color (white or black)
    square.IsWhite = !square.IsWhite;

    squares.Remove(square);
    squares.Add(square);

    antPositions.Insert(i, new AntPosition(currentAntPosition));
}

//foreach (var ap in antPositions)
//{
//    Console.Write($"   Move #: {ap.Id.ToString("00000")} | ");
//    Console.Write($"Direction: {ap.Direction.ToString("000")} |");
//    Console.Write($"X: {ap.X} |");
//    Console.Write($"Y: {ap.Y} |");
//    Console.WriteLine();
//}

//foreach (var sq in squares)
//{
//    Console.WriteLine($"({sq.X},{sq.Y}): {sq.IsWhite}");
//}

int minX = 0;
int maxX = 0;
int minY = 0;
int maxY = 0;

minX = squares.Min(s => s.X);
maxX = squares.Max(s => s.X);
minY = squares.Min(s => s.Y);
maxY = squares.Max(s => s.Y);

Console.WriteLine("Min X = " + minX + " | Min Y = " + minY);
Console.WriteLine("Max X = " + maxX + " | Max Y = " + maxY);

Console.WriteLine("----------");
for (int x = minX; x <= maxX; x++)
{
    for (int y = maxY; y >= minY; y--)
    {
        var square = squares.SingleOrDefault(s => s.X == x && s.Y == y) ?? new Square(x, y);

        if (square.IsWhite)
            Console.Write(" ");
        else
            Console.Write("X");
    }
    Console.WriteLine();
}
Console.WriteLine("----------");
Console.WriteLine("X = black square");
Console.WriteLine("<space> = white square");

string jsonData = JsonSerializer.Serialize(squares);

File.WriteAllText(@"C:\Users\olearys\source\repos\LangtonsAnt\LangtonsAntCSharp\data.json", jsonData);
File.WriteAllText(@"C:\Users\olearys\source\repos\LangtonsAnt\LangtonsAntCSharp\moves.txt", $"K = {K}");