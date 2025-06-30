class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    vector<int> result;

    int row = matrix.size();
    int col = matrix[0].size();

    int total = row * col;
    int count = 0;

    int startRow = 0, endRow = row - 1;
    int startCol = 0, endCol = col - 1;

    while (count < total)
    {
      for (int idx = startCol; count < total && idx <= endCol; idx++)
      {
        result.push_back(matrix[startRow][idx]);
        count++;
      }
      startRow++;

      for (int idx = startRow; count < total && idx <= endRow; idx++)
      {
        result.push_back(matrix[idx][endCol]);
        count++;
      }
      endCol--;

      for (int idx = endCol; count < total && idx >= startCol; idx--)
      {
        result.push_back(matrix[endRow][idx]);
        count++;
      }
      endRow--;

      for (int idx = endRow; count < total && idx >= startRow; idx--)
      {
        result.push_back(matrix[idx][startCol]);
        count++;
      }
      startCol++;
    }

    return result;
  }
};
