#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc cho mỗi người
struct Person
{
    char ho[50];
    char tenDem[50];
    char ten[50];
};

// Hàm so sánh hai người
int comparePeople(const void *a, const void *b)
{
    // So sánh theo tên
    int tenComparison = strcmp(((struct Person *)a)->ten, ((struct Person *)b)->ten);
    if (tenComparison != 0)
    {
        return tenComparison;
    }

    // Nếu tên giống nhau, so sánh theo họ
    int hoComparison = strcmp(((struct Person *)a)->ho, ((struct Person *)b)->ho);
    if (hoComparison != 0)
    {
        return hoComparison;
    }

    // Nếu họ giống nhau, so sánh theo tên đệm
    return strcmp(((struct Person *)a)->tenDem, ((struct Person *)b)->tenDem);
}

int main()
{
    // Khởi tạo một mảng người
    struct Person people[] = {
        {"Le", "Tuan", "Minh"},
        {"Nguyen", "Van", "An"},
        {"Tran", "Thi", "Binh"},
        // Thêm các người khác tại đây
    };

    // Số lượng người trong mảng
    int numPeople = sizeof(people) / sizeof(people[0]);

    // Sắp xếp mảng người
    qsort(people, numPeople, sizeof(people[0]), comparePeople);

    // In danh sách người đã sắp xếp
    printf("Danh sach nguoi sau khi sap xep:\n");
    for (int i = 0; i < numPeople; i++)
    {
        printf("%s %s %s\n", people[i].ho, people[i].tenDem, people[i].ten);
    }

    return 0;
}
