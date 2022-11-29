#include <gtest/gtest.h>
#include "/mnt/d/CLionProjects/laba-3/lib.h"

TEST (CheckArgs, Test1) {
    int len = 1;
    char** a = new char*[1];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    EXPECT_EQ(0, check_args(len, a));
    delete []a;
}

TEST (CheckArgs, Test2) {
    int len = 2;
    char** a = new char*[2];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[10];
    a[1][0] = '-'; a[1][1] = '-'; a[1][2] = 'f'; a[1][3] = 'r'; a[1][4] = 'o'; a[1][5] = 'm'; a[1][6] = 'f';
    a[1][7] = 'i'; a[1][8] = 'l'; a[1][9] = 'e';
    EXPECT_EQ(1, check_args(len, a));
    delete []a[0]; delete []a[1];
    delete []a;
}

TEST (CheckArgs, Test3) {
    int len = 2;
    char** a = new char*[2];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[8];
    a[1][0] = '-'; a[1][1] = '-'; a[1][2] = 't'; a[1][3] = 'o'; a[1][4] = 'f';
    a[1][5] = 'i'; a[1][6] = 'l'; a[1][7] = 'e';
    EXPECT_EQ(2, check_args(len, a));
    delete []a[0]; delete []a[1];
    delete []a;
}

TEST (CheckArgs, Test4) {
    int len = 2;
    char** a = new char*[2];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[8];
    a[1][0] = '+'; a[1][1] = '+'; a[1][2] = 't'; a[1][3] = 'o'; a[1][4] = 'f';
    a[1][5] = 'i'; a[1][6] = 'l'; a[1][7] = 'e';
    EXPECT_EQ(-1, check_args(len, a));
    delete []a[0]; delete []a[1];
    delete []a;
}

TEST (CheckArgs, Test5) {
    int len = 3;
    char** a = new char*[3];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[8];
    a[1][0] = '-'; a[1][1] = '-'; a[1][2] = 't'; a[1][3] = 'o'; a[1][4] = 'f';
    a[1][5] = 'i'; a[1][6] = 'l'; a[1][7] = 'e';
    a[2] = new char[10];
    a[2][0] = '-'; a[2][1] = '-'; a[2][2] = 'f'; a[2][3] = 'r'; a[2][4] = 'o'; a[2][5] = 'm'; a[2][6] = 'f';
    a[2][7] = 'i'; a[2][8] = 'l'; a[2][9] = 'e';
    EXPECT_EQ(3, check_args(len, a));
    delete []a[0]; delete []a[1]; delete []a[2];
    delete []a;
}

TEST (CheckArgs, Test6) {
    int len = 3;
    char** a = new char*[3];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[10];
    a[1][0] = '-'; a[1][1] = '-'; a[1][2] = 'f'; a[1][3] = 'r'; a[1][4] = 'o'; a[1][5] = 'm'; a[1][6] = 'f';
    a[1][7] = 'i'; a[1][8] = 'l'; a[1][9] = 'e';
    a[2] = new char[8];
    a[2][0] = '-'; a[2][1] = '-'; a[2][2] = 't'; a[2][3] = 'o'; a[2][4] = 'f';
    a[2][5] = 'i'; a[2][6] = 'l'; a[2][7] = 'e';
    EXPECT_EQ(3, check_args(len, a));
    delete []a[0]; delete []a[1]; delete []a[2];
    delete []a;
}

TEST (CheckArgs, Test7) {
    int len = 3;
    char** a = new char*[3];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[10];
    a[1][0] = '-'; a[1][1] = '-'; a[1][2] = 'f'; a[1][3] = 'r'; a[1][4] = 'o'; a[1][5] = 'm'; a[1][6] = 'f';
    a[1][7] = 'i'; a[1][8] = 'l'; a[1][9] = 'e';
    a[2] = new char[8];
    a[2][0] = '+'; a[2][1] = '+'; a[2][2] = 't'; a[2][3] = 'o'; a[2][4] = 'f';
    a[2][5] = 'i'; a[2][6] = 'l'; a[2][7] = 'e';
    EXPECT_EQ(-1, check_args(len, a));
    delete []a[0]; delete []a[1]; delete []a[2];
    delete []a;
}

TEST (CheckArgs, Test8) {
    int len = 3;
    char** a = new char*[3];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[10];
    a[1][0] = '+'; a[1][1] = '+'; a[1][2] = 'f'; a[1][3] = 'r'; a[1][4] = 'o'; a[1][5] = 'm'; a[1][6] = 'f';
    a[1][7] = 'i'; a[1][8] = 'l'; a[1][9] = 'e';
    a[2] = new char[8];
    a[2][0] = '+'; a[2][1] = '+'; a[2][2] = 't'; a[2][3] = 'o'; a[2][4] = 'f';
    a[2][5] = 'i'; a[2][6] = 'l'; a[2][7] = 'e';
    EXPECT_EQ(-1, check_args(len, a));
    delete []a[0]; delete []a[1]; delete []a[2];
    delete []a;
}

TEST (CheckArgs, Test9) {
    int len = 4;
    char** a = new char*[4];
    a[0] = new char[6];
    a[0][0] = '.'; a[0][1] = '/'; a[0][2] = 'm'; a[0][3] = 'a'; a[0][4] = 'i'; a[0][5] = 'n';
    a[1] = new char[10];
    a[1][0] = '-'; a[1][1] = '-'; a[1][2] = 'f'; a[1][3] = 'r'; a[1][4] = 'o'; a[1][5] = 'm'; a[1][6] = 'f';
    a[1][7] = 'i'; a[1][8] = 'l'; a[1][9] = 'e';
    a[2] = new char[8];
    a[2][0] = '-'; a[2][1] = '-'; a[2][2] = 't'; a[2][3] = 'o'; a[2][4] = 'f';
    a[2][5] = 'i'; a[2][6] = 'l'; a[2][7] = 'e';
    a[3] = new char[4];
    a[3][0] = 'b'; a[3][1] = 'o'; a[3][2] = 'o'; a[3][3] = 'm';
    EXPECT_EQ(-1, check_args(len, a));
    delete []a[0]; delete []a[1]; delete []a[2]; delete []a[3];
    delete []a;
}

TEST (CheckSort, Test1){
    int len = 5;
    int** a = new int*[5];
    a[0] = new int[1]; a[0][0] = 5;
    a[1] = new int[1]; a[1][0] = 4;
    a[2] = new int[1]; a[2][0] = 3;
    a[3] = new int[1]; a[3][0] = 2;
    a[4] = new int[1]; a[4][0] = 1;

    int** answ = new int*[5];
    answ[0] = new int[1]; answ[0][0] = 1;
    answ[1] = new int[1]; answ[1][0] = 2;
    answ[2] = new int[1]; answ[2][0] = 3;
    answ[3] = new int[1]; answ[3][0] = 4;
    answ[4] = new int[1]; answ[4][0] = 5;

    sort(a, len);
    for(int i = 0; i < 5; ++i){
        EXPECT_EQ(answ[i][0], a[i][0]);
    }
    for(int i = 0; i < 5; ++i){
        delete []answ[i];
        delete []a[i];
    }
    delete []answ;
    delete []a;
}

TEST (CheckSort, Test2){
    int len = 10;
    int** a = new int*[10];
    int** answ = new int*[10];
    for(int i = 0; i < 10; ++i){
        a[i] = new int[3];
        answ[i] = new int[3];
        for(int j = 0; j < 3; ++j){
            a[i][j] = 1;
            answ[i][j] = 1;
        }
    }
    a[0][0] = -10; a[1][0] = -20; a[2][0] = 0; a[3][0] = 100; a[4][0] = 1;
    a[5][0] = 5; a[6][0] = 2; a[7][0] = 3; a[8][0] = 4; a[9][0] = 6;
    answ[0][0] = -20; answ[1][0] = -10; answ[2][0] = 0; answ[3][0] = 1; answ[4][0] = 2;
    answ[5][0] = 3; answ[6][0] = 4; answ[7][0] = 5; answ[8][0] = 6; answ[9][0] = 100;

    sort(a, len);

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 3; ++j){
            EXPECT_EQ(answ[i][j], a[i][j]);
        }
    }

    for(int i = 0; i < 10; ++i){
        delete []answ[i];
        delete []a[i];
    }
    delete []answ;
    delete []a;


}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}