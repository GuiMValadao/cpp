/* Multi-dimensional arrays of variable length
This program receives the number of courses, then, in each course, a number of grades,
then the grades (numbering the entered amount). Then it calculates the average per course
and the total average, printing the final results and individual grades per course, along with
an overal final result.
*/

#include <iostream>

using namespace std;
int main(void) {
    
    int number_courses, number_grades;
    double total_grade_sum = 0.0;
    
    //cout << "The number of courses is ";
    cin >> number_courses;
    if (cin.good() && number_courses > 0) {
        int **classes_grades = new int *[number_courses];
        double *classes_finals = new double[number_courses];
        for (int c = 0; c < number_courses; c++) {
            //cout << "The number of grades for the current course is ";
            cin >> number_grades;
            if(number_grades < 1) {
                cout << "There must be at least one grade.";
                return 1;
            }
            classes_grades[c] = new int[number_grades + 1];
            classes_grades[c][0] = number_grades;
            long course_grade_sum = 0;

            int grade;
            for (int g = 1; g <= number_grades; g++) {
                //cout << "The grades are ";
                cin >> grade;
                if (grade < 1 || grade > 5) {
                    cout << "Grades must be between 1 and 5" << endl;
                    g--;
                    continue;
                }
                classes_grades[c][g] = grade;
                course_grade_sum += grade;
            }
            classes_finals[c] = double(course_grade_sum) / number_grades;
            total_grade_sum += classes_finals[c];
        }
    
        cout.precision(2);
        cout << fixed;
        float final_sum = 0;
        for (int course = 0; course < number_courses; course++) {
            cout << "Course " << course + 1 << ": ";
            cout << "final " << classes_finals[course] << ", grades: ";
            for (int grades = 0; grades < classes_grades[course][0]; grades++) {
                cout << classes_grades[course][grades+1] << " ";
            }
            cout << endl;

        }
        cout << "Overal final: " << total_grade_sum / number_courses;
        for (int r = 0; r < number_courses; r++)
            delete[] classes_grades[r];
        delete[] classes_grades;
        delete[] classes_finals;
    }
    return 0;
}