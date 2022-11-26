#include <gtest/gtest.h>
#include "/mnt/c/Users/proko/CLionProjects/lab5/func.h"

//enter
TEST (Wrongenter, Test1) {
    int argc = 4;
    char** argv;
    EXPECT_EQ(0, checkflag(argc, argv));
}

TEST (Wrongenter, Test2){
    int argc = 2;
    char ar1[6] = {'.', '/', 'm', 'a', 'i', 'n'};
    char ar2[8] = {'8', '8', 't', 'o', 'f', 'i', 'l', 'e'};
    char* ar[2] = {ar1, ar2};
    EXPECT_EQ(0, checkflag(argc, ar));
}

TEST (Rightenter, Test2){
    int argc = 2;
    char ar1[6] = {'.', '/', 'm', 'a', 'i', 'n'};
    char ar2[8] = {'-', '-', 't', 'o', 'f', 'i', 'l', 'e'};
    char* ar[2] = {ar1, ar2};
    EXPECT_EQ(1, checkflag(argc, ar));
}

//enter2
TEST (Rightmas, Test1){
    double seg[4] = {1.2, 2.3, 2.4, 7.8};
    EXPECT_EQ (checkmas(seg, 4), 1);
}

TEST (Rightmas, Test2){
    double seg[4] = {1.2, 1, 2.4, 7.8};
    EXPECT_EQ (checkmas(seg, 4), 0);
}

TEST (Rightsort, Test2){
    double seg[4] = {1.2, 2.3, 2.4, 7.8};
    double segright[4] = {1.2, 2.3, 2.4, 7.8};;
    sortmas(seg, 4);
    for (int i = 0; i < 4; ++i){
        EXPECT_EQ (seg[i], segright[i]);
    }
}

//sort
TEST (Rightsort, Test1){
    double seg[10] = {1.2, 3.4, -1.8, 0.1, 0.5, 1.5, 1.3, 2.8, -2, -1};
    double segright[10] = {-2, -1, -1.8, 0.1, 0.5, 1.5, 1.2, 3.4, 1.3, 2.8};
    sortmas(seg, 10);
    for (int i = 0; i < 10; ++i){
        EXPECT_EQ (seg[i], segright[i]);
    }
}

TEST (Rightsort, Test3){
    double seg[6] = {1.2, 2.3, 2.4, 7.8, -7.72, 6};
    double segright[6] = {-7.72, 6, 1.2, 2.3, 2.4, 7.8};
    sortmas(seg, 6);
    for (int i = 0; i < 6; ++i){
        EXPECT_EQ (seg[i], segright[i]);
    }
}

//con
TEST (Rightcon, Test1){
    double seg[4] = {1.2, 2.3, 2.4, 7.8};
    double segright[4] = {1.2, 2.3, 2.4, 7.8};
    char argv[][2] = {{'1', '2'}, {'1', '1'}};
    char **argvf;
    char* a = &argv[0][0];
    argvf = &a;
    int argc = 2;
    conjunction(seg, 4, argc, argvf);
    for (int i = 0; i < 4; ++i){
        EXPECT_EQ (seg[i], segright[i]);
    }
}

TEST (Rightcon, Test2){
    double seg[4] = {1.2, 2.7, 2.4, 7.8};
    double segright[4] = {0.001, 0.001, 1.2, 7.8};
    char argv[][2] = {{'1', '2'}, {'1', '1'}};
    char **argvf;
    char* a = &argv[0][0];
    argvf = &a;
    int argc = 2;
    conjunction(seg, 4, argc, argvf);
    for (int i = 0; i < 4; ++i){
        EXPECT_EQ (seg[i], segright[i]);
    }
}

TEST (Rightcon, Test3){
    double seg[10] = {-2, -1, -1.8, 0.1, 0.5, 1.5, 1.2, 3.4, 1.3, 2.8};
    double segright[10] = {0.001, 0.001,-2, 0.1, 0.001, 0.001, 0.001, 0.001, 0.5, 3.4};
    char argv[][2] = {{'1', '2'}, {'1', '1'}};
    char **argvf;
    char* a = &argv[0][0];
    argvf = &a;
    int argc = 2;
    conjunction(seg, 4, argc, argvf);
    for (int i = 0; i < 4; ++i){
        EXPECT_EQ (seg[i], segright[i]);
    }
}

TEST (Rightcon, Test4){
    double seg[6] = {-7.72, 6, 1.2, 2.3, 2.4, 7.8};
    double segright[6] = {0.001, 0.001, 0.001, 0.001, -7.72, 7.8};
    char argv[][2] = {{'1', '2'}, {'1', '1'}};
    char **argvf;
    char* a = &argv[0][0];
    argvf = &a;
    int argc = 2;
    conjunction(seg, 6, argc, argvf);
    for (int i = 0; i < 6; ++i){
        EXPECT_EQ (seg[i], segright[i]);
    }
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
