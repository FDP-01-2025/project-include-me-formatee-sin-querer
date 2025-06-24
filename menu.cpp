#include <iostream>

using namespace std;

int main()
{

    int option = 0, option2 = 0;

    while (option != 2)
    {
        cout << "--------Menu---------" << endl;
        cout << "1. play" << endl;
        cout << "2. Go out" << endl;
        cout << "choose a option" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "___________________________________" << endl;
            while (option2 != 7)
            {
                cout << "--------Menu---------" << endl;
                cout << "1. level 1" << endl;
                cout << "2. level 2" << endl;
                cout << "3. level 3" << endl;
                cout << "4. level 4" << endl;
                cout << "5. level 5" << endl;
                cout << "6. level 6" << endl;
                cout << "7. level 7" << endl;
                cout << "8. level 8" << endl;
                cout << "9. level 9" << endl;
                
                cout << "choose your level" << endl;
                cin>>option2;
                switch (option2)
                {
                case 1:
                cout << "1. level 1" << endl;
                    break;
                case 2:
                cout << "2. level 2" << endl;
                    break;
                case 3:
                cout << "3. level 3" << endl;
                    break;
                case 4:
                cout << "4. level 4" << endl;
                    break;
                case 5:
                cout << "5. level 5" << endl;
                    break;
                case 6:
                cout << "6. level 6" << endl;
                    break;
                case 7:
                cout << "7. level 7" << endl;
                    break;
                case 8:
                cout << "8. level 8" << endl;
                    break;
                case 9:
                cout << "9. level 9" << endl;
                    break;
                default:
                cout << "write a correct option" << endl;
                
                    break;
                }


            }

            break;
        case 2:
            return 0;
            break;
            cout << "Write a correct option" << endl;
        default:
            break;
        }
        cout << "" << endl;
    }

    return 0;
}