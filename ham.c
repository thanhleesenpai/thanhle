1. Nếu hàm xóa bộ đệm bàn phím không hoạt động, bạn có thể tham khảo cách sau void clearStdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

2. Hàm fgets sẽ đọc cả vào dấu \n khi đọc xâu, vì thế nên dùng thêm hàm để loại bỏ ký tự này void standaliseString(char *str)
{
    while (strlen(str) > 0 && (str[strlen(str) - 1] == '\r' || str[strlen(str) - 1] == '\n'))
        str[strlen(str) - 1] = '\0';
}
// kiem tra mot so co la mot phan tu trong mang
int ktpt(int a[], int max, int b)
{
    for (int i = 0; i < max; i++)
    {
        if (a[i] = b)
        {
            return 1;
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

// Hàm viết hoa ký tự đầu của mỗi từ trong 1 chuỗi cho trước
char *vietHoaKyTuDau(char *S)
{
    char *ketQua = new char[strlen(S)];

    if (S[0] != ' ' && S[0] >= 97)
        ketQua[0] = S[0] - 32;
    else
        ketQua[0] = S[0];

    for (int i = 1; i < strlen(S); i++)
    {
        ketQua[i] = S[i];
        if (S[i] == ' ' && S[i + 1] != ' ' && S[i + 1] >= 97)
        {
            ketQua[i + 1] = S[i + 1] - 32;
            i++;
        }
    }

    ketQua[strlen(S)] = '\0';

    return ketQua;
}

int main()
{
    char S[300];

    printf("Nhap vao chuoi Input: ");
    fflush(stdin);
    fgets(S, 300, stdin);

    printf("Output: ");
    char *ketQua = vietHoaKyTuDau(S);

    puts(ketQua);
}

1. Nếu hàm xóa bộ đệm bàn phím không hoạt động, bạn có thể tham khảo cách sau void clearStdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

2. Hàm fgets sẽ đọc cả vào dấu \n khi đọc xâu, vì thế nên dùng thêm hàm để loại bỏ ký tự này void standaliseString(char *str)
{
    while (strlen(str) > 0 && (str[strlen(str) - 1] == '\r' || str[strlen(str) - 1] == '\n'))
        str[strlen(str) - 1] = '\0';