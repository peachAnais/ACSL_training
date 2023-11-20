//ACSL 2023 - 2024

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//set up the matrix with the target positions

//separate the target string into a vector where each element correspond to an individual target
//status: works, returns the vector with all the target location.
vector<string> separateTargets(string targets){

    vector<string> result;

    string target_str = "";
    for(int i = 0; i < targets.length(); i++) {

        if(targets.at(i) != ' ') {
            target_str += targets.at(i);
        }

        if(target_str.length() == 2) {
            result.push_back(target_str);
            target_str = "";
        }
    }

    return result;
}

//set up another matrix that shows the correspindence between the row of the taget with the column of a target
//this matrix will constist of 2 rows: on each column, the upper row will correspond to the rows of the target and the lower row will correspong to the column of the target
//the last row will show how many arrows intercept this target without hitting any other targets
vector<vector<int>> createTargetMatrix(vector<string> target_locations) {
    vector<vector<int>> mat(3, vector<int>(target_locations.size()));

    int col_index = 0;

    for(int i = 0; i < target_locations.size(); i++){
        
        string current_location = target_locations.at(i);

        mat[0][col_index] = current_location.at(0) - '0';
        mat[1][col_index] = current_location.at(1) - '0';
        mat[2][col_index] = 0;

        col_index++;
    }

    return mat;
}

//check if an arrow hits more than 1 target
//takes as parameters the size of the matrix that conatins all target, the matrix that show the correspondance between the targets

//for arrows A through H, create a function for each type of arrows that checks whether or not it will hit more than 1 target
//if it doesn't, it will updated in the second row of the target matrix the number of arrows that soleley hit the coresponding target
void checkA(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix){
    int targets_hit = 0;
    int current_row = starting_row;

    int last_it_target_col;

    //check if the rows exists as a possible location for a target
    //if it does, for all the columns to the left of the starting column, check if there are any correspondances with the column associated to the row in the target_loc_matrix
    for(int i = 0; i < target_loc_matrix.size(); i++) {

        if(current_row == target_loc_matrix[0][i]) {
            
            for(int j = starting_col; j > 0; j++) {
                if(target_loc_matrix[1][i] == j) {
                    targets_hit++;
                    last_it_target_col = i;
                }
            }
        }
    }

    if(targets_hit == 1){
        target_loc_matrix[2][last_it_target_col]++;
    }
}

void checkB(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix){
    int targets_hit = 0;
    int current_col = starting_col;
    int last_target_hit_col;

    for(int i = 0; i < target_loc_matrix.size(); i++) {

        if(current_col == target_loc_matrix[1][i]) {

            for(int j = starting_row; j > 0; j--) {
                if(target_loc_matrix[0][i] == j) {
                    targets_hit++;
                    last_target_hit_col = i;
                }
            }
        }
    }

    if(targets_hit == 1) {
        target_loc_matrix[2][last_target_hit_col]++;
    }

}

void checkC(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix, int original_matrix_size) {
    int targets_hit = 0;
    int current_row = starting_row;

    int last_it_target_col;

    //check if the rows exists as a possible location for a target
    //if it does, for all the columns to the left of the starting column, check if there are any correspondances with the column associated to the row in the target_loc_matrix
    for(int i = 0; i < target_loc_matrix.size(); i++) {

        if(current_row == target_loc_matrix[0][i]) {
            
            for(int j = starting_col; j < original_matrix_size - 1; j++) {
                if(target_loc_matrix[1][i] == j) {
                    targets_hit++;
                    last_it_target_col = i;
                }
            }
        }
    }

    if(targets_hit == 1){
        target_loc_matrix[2][last_it_target_col]++;
    }
}

void checkD(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix, int original_matrix_size) {
int targets_hit = 0;
    int current_col = starting_col;
    int last_target_hit_col;

    for(int i = 0; i < target_loc_matrix.size(); i++) {

        if(current_col == target_loc_matrix[1][i]) {

            for(int j = starting_row; j < original_matrix_size - 1; j++) {
                if(target_loc_matrix[0][i] == j) {
                    targets_hit++;
                    last_target_hit_col = i;
                }
            }
        }
    }

    if(targets_hit == 1) {
        target_loc_matrix[2][last_target_hit_col]++;
    }
}

void checkE(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix) {
    int targets_hit = 0;
    int last_hit_target_col;

    for(int current_row = starting_row, current_col = starting_col; current_row > 0, current_col > 0; current_row--, current_col--) {
        
        for(int i = 0; i < target_loc_matrix.size(); i++) {
            if(target_loc_matrix[0][i] == current_row && target_loc_matrix[1][i] == current_col){
                targets_hit++;
                last_hit_target_col = i;
            }
        }
    }

    if(targets_hit == 1) {
        target_loc_matrix[2][last_hit_target_col]++;
    }
}


void checkF(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix, int original_matrix_size) {
    int targets_hit = 0;
    int last_hit_col;

    for(int current_row = starting_row, current_col = starting_col; current_row > 0, current_col < original_matrix_size - 1; current_row--, current_col++) {
        
        for(int i = 0; i < target_loc_matrix.size(); i++) {
            if(target_loc_matrix[0][i] == current_row && target_loc_matrix[1][i] == current_col) {
                targets_hit++;
                last_hit_col = i;
            }
        }
    }

    if(targets_hit == 1) {
        target_loc_matrix[2][last_hit_col]++; 
    }
}

void checkG(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix, int original_matrix_size) {
    int targets_hit = 0;
    int last_hit_col;

    for(int current_row = starting_row, current_col = starting_col; current_row < original_matrix_size - 1, current_col < original_matrix_size - 1; current_row++, current_col++) {
        
        for(int i = 0; i < target_loc_matrix.size(); i++) {
            if(target_loc_matrix[0][i] == current_row && target_loc_matrix[1][i] == current_col) {
                targets_hit++;
                last_hit_col = i;
            }
        }
    }

    if(targets_hit == 1) {
        target_loc_matrix[2][last_hit_col]++; 
    }
}

void checkH(int starting_row, int starting_col, vector<vector<int>> &target_loc_matrix, int original_matrix_size) {
    int targets_hit = 0;
    int last_hit_col;

    for(int current_row = starting_row, current_col = starting_col; current_row < original_matrix_size - 1, current_col > 0; current_row++, current_col--) {
        
        for(int i = 0; i < target_loc_matrix.size(); i++) {
            if(target_loc_matrix[0][i] == current_row && target_loc_matrix[1][i] == current_col) {
                targets_hit++;
                last_hit_col = i;
            }
        }
    }

    if(targets_hit == 1) {
        target_loc_matrix[2][last_hit_col]++; 
    }
}

//solve
void solve(int size, string targets){

    vector<string> separated_targets = separateTargets(targets);

    vector<vector<int>> target_loc_matrix = createTargetMatrix(separated_targets);

    //all the columns of the first row
    for(int current_col = 0; current_col < size; current_col++) {
        checkA(0, current_col, target_loc_matrix);
        checkB(0, current_col, target_loc_matrix);
        checkC(0, current_col, target_loc_matrix, size);
        checkD(0, current_col, target_loc_matrix, size);
        checkE(0, current_col, target_loc_matrix);
        checkF(0, current_col, target_loc_matrix, size);
        checkG(0, current_col, target_loc_matrix, size);
        checkH(0, current_col, target_loc_matrix, size);
    }

    //all the rows of the first column
    for(int current_row = 1; current_row < size; current_row++) {
        checkA(current_row, 0, target_loc_matrix);
        checkB(current_row, 0, target_loc_matrix);
        checkC(current_row, 0, target_loc_matrix, size);
        checkD(current_row, 0, target_loc_matrix, size);
        checkE(current_row, 0, target_loc_matrix);
        checkF(current_row, 0, target_loc_matrix, size);
        checkG(current_row, 0, target_loc_matrix, size);
        checkH(current_row, 0, target_loc_matrix, size);
    }

    //all the columns of the last row
    for(int current_col = 1; current_col < size; current_col++) {
        checkA(size - 1, current_col, target_loc_matrix);
        checkB(size - 1, current_col, target_loc_matrix);
        checkC(size - 1, current_col, target_loc_matrix, size);
        checkD(size - 1, current_col, target_loc_matrix, size);
        checkE(size - 1, current_col, target_loc_matrix);
        checkF(size - 1, current_col, target_loc_matrix, size);
        checkG(size - 1, current_col, target_loc_matrix, size);
        checkH(size - 1, current_col, target_loc_matrix, size);
    }

    //all the rows of the last column
    for(int current_row = 1; current_row < size; current_row++) {
        checkA(current_row, size - 1, target_loc_matrix);
        checkB(current_row, size - 1, target_loc_matrix);
        checkC(current_row, size - 1, target_loc_matrix, size);
        checkD(current_row, size - 1, target_loc_matrix, size);
        checkE(current_row, size - 1, target_loc_matrix);
        checkF(current_row, size - 1, target_loc_matrix, size);
        checkG(current_row, size - 1, target_loc_matrix, size);
        checkH(current_row, size - 1, target_loc_matrix, size);
    }

    int max_row;
    int max_col;
    int max_hits = -1;
    for(int i = 0; i < target_loc_matrix.size(); i++) {
        if(target_loc_matrix[2][i] > max_hits) {
            max_hits = target_loc_matrix[2][i];
            max_row = target_loc_matrix[0][i];
            max_col = target_loc_matrix[1][i];
        }
    }

    string target_searched_for = to_string(max_row) + to_string(max_col);

    cout << "Target we search for it at follwing location: " + target_searched_for << endl;
}

int main(void) {

    solve(6, "13 21 41 42 44");
}