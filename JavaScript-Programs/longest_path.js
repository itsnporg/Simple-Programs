// JavaScript program to find the longest path in a matrix
// with given constraints
let n = 3;

// Returns length of the longest path beginning with mat[i][j].
// This function mainly uses lookup table dp[n][n]
function findLongestFromACell(i, j, mat, dp) {
  if (i < 0 || i >= n || j < 0 || j >= n) return 0;

  // If this subproblem is already solved
  if (dp[i][j] != -1) return dp[i][j];

  // To store the path lengths in all the four directions

  let x, y, z, w;
  x = -1;
  y = -1;
  z = -1;
  w = -1;

  // Since all numbers are unique and in range from 1 to n*n,
  // there is atmost one possible direction from any cell
  if (j < n - 1 && mat[i][j] + 1 == mat[i][j + 1])
    x = 1 + findLongestFromACell(i, j + 1, mat, dp);

  if (j > 0 && mat[i][j] + 1 == mat[i][j - 1])
    y = 1 + findLongestFromACell(i, j - 1, mat, dp);

  if (i > 0 && mat[i][j] + 1 == mat[i - 1][j])
    z = 1 + findLongestFromACell(i - 1, j, mat, dp);

  if (i < n - 1 && mat[i][j] + 1 == mat[i + 1][j])
    w = 1 + findLongestFromACell(i + 1, j, mat, dp);

  // If none of the adjacent fours is one greater we will take 1
  // otherwise we will pick maximum from all the four directions
  dp[i][j] = Math.max(x, Math.max(y, Math.max(z, Math.max(w, 1))));
  return dp[i][j];
}

// Returns length of the longest path beginning with any cell
function finLongestOverAll(mat) {
  let result = 1; // Initialize result

  // Create a lookup table and fill all entries in it as -1
  var dp = [];

  for (var y = 0; y < n; y++) {
    dp[y] = [];
    for (var x = 0; x < n; x++) {
      dp[y][x] = -1;
    }
  }

  // Compute longest path beginning from all cells
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (dp[i][j] == -1) findLongestFromACell(i, j, mat, dp);

      // Update result if needed
      result = Math.max(result, dp[i][j]);
    }
  }

  return result;
}

// Driver program
let mat = [
  [1, 2, 9],
  [5, 3, 8],
  [4, 6, 7],
];

document.write("Length of the longest path is ");
document.write(finLongestOverAll(mat));
