//
//  main.cpp
//  Unittest
//
//  Created by 문정환 on 5/24/24.
//

#include "Header.h"
#include <iostream>
using namespace std;

// 테스트를 위한 SortedType 객체를 생성합니다.
SortedType<int> sortedList;

// isEmpty 함수 테스트
void TestIsEmptyOnNewListReturnsTrue() {
    if (sortedList.isEmpty()) {
        cout << "TestIsEmptyOnNewListReturnsTrue: 성공" << endl;
    } else {
        cout << "TestIsEmptyOnNewListReturnsTrue: 실패" << endl;
    }
}

// isFull 함수 테스트
void TestIsFullReturnsFalse() {
    if (!sortedList.isFull()) {
        cout << "TestIsFullReturnsFalse: 성공" << endl;
    } else {
        cout << "TestIsFullReturnsFalse: 실패" << endl;
    }
}

// insertItem과 size 함수 테스트
void TestInsertItemIncreasesSize() {
    sortedList.insertItem(10);
    if (sortedList.size() == 1) {
        cout << "TestInsertItemIncreasesSize: 성공" << endl;
    } else {
        cout << "TestInsertItemIncreasesSize: 실패" << endl;
    }
}

// findItem 함수 테스트
void TestFindItemReturnsTrueForExistingItem() {
    int item = 20;
    sortedList.insertItem(item);
    if (sortedList.findItem(item)) {
        cout << "TestFindItemReturnsTrueForExistingItem: 성공" << endl;
    } else {
        cout << "TestFindItemReturnsTrueForExistingItem: 실패" << endl;
    }
}



int main() {
    TestIsEmptyOnNewListReturnsTrue();
    TestIsFullReturnsFalse();
    TestInsertItemIncreasesSize();
    TestFindItemReturnsTrueForExistingItem();

    return 0;
}
