public class Solution {
    public int CountUnguarded(int m, int n, int[][] guards, int[][] walls)
    {
        var count = m * n;
        Span<int> calls = stackalloc int[count];

        count -= walls.Length;

        foreach (var wall in walls)
        {
            var index = wall[0] * n + wall[1];
            calls[index] = -1;
        }

        count -= guards.Length;

        foreach (var guard in guards)
        {
            var index = guard[0] * n + guard[1];
            calls[index] = -1;
        }

        Span<int> rowIncr = stackalloc int[4] { 1, -1, 0, 0 };
        Span<int> colIncr = stackalloc int[4] { 0, 0, 1, -1 };

        foreach (var guard in guards)
        {
            for (var i = 0; i < 4; i++)
            {
                var row = guard[0] + rowIncr[i];
                var col = guard[1] + colIncr[i];

                while (row >= 0 && row < m && col >= 0 && col < n)
                {
                    var newIndex = row * n + col;
                    if (calls[newIndex] == -1)
                    {
                        break;
                    }
                    else if (calls[newIndex] == 0)
                    {
                        calls[newIndex] = 1;
                        count--;
                    }
                    row += rowIncr[i];
                    col += colIncr[i];
                }
            }
        }

        return count;
    }
}
