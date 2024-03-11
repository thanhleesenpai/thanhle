#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// định nghĩa 1 nút trong danh sách liên kết biểu diễn đa thức bậc n
struct Node
{
    double heSo;
    int soMu;
    struct Node *next;
};

/*
hàm cấp phát động một nút mới của danh sách và gán giá trị khởi tạo cho nút
*/

struct Node *createNewNode(double heSo, int soMu)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->heSo = heSo;
    p->soMu = soMu;
    p->next = NULL;

    return p;
}

/*
 * Hàm clone phần tử
 */
struct Node *copyNode(struct Node *nSource)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->heSo = nSource->heSo;
    p->soMu = nSource->soMu;
    p->next = NULL;

    return p;
}

/*
Hàm nhập vào một đa thức bậc n với số mũ giảm dần
*/

struct Node *readData()
{
    struct Node *head = NULL, *p, *last = NULL;
    double heSo;
    int soMu, nElement;

    // doc vao so luong phan tu cua da thuc
    scanf("%d", &nElement);

    // doc vao tung phan tu
    for (int i = 0; i < nElement; i++)
    {
        scanf("%lf", &heSo);
        scanf("%d", &soMu);
        if (head == NULL)
        { // nếu đang rỗng thì thêm vào đầu
            head = createNewNode(heSo, soMu);
            last = head;
        }
        else
        { // ngược lại thêm vào cuối
            p = createNewNode(heSo, soMu);
            last->next = p;
            last = p;
        }
    }

    return head;
}

/**
In đa thức bậc n hiện có
*/

void printData(struct Node *head)
{
    printf("Content: ");
    int n = 0;
    while (head != NULL)
    {
        if (n > 0 && head->heSo > 0)
        {
            printf("+");
        }

        if (head->soMu > 1)
        {
            if (head->heSo != 1)
            {
                printf("%.2lf x^%d ", head->heSo, head->soMu);
            }
            else
            {
                printf("x^%d ", head->soMu);
            }
        }
        else if (head->soMu == 1)
        {
            if (head->heSo != 1)
            {
                printf("%.2lf x ", head->heSo);
            }
            else
            {
                printf(" x ");
            }
        }
        else
        {
            printf("%.2lf", head->heSo);
        }

        head = head->next;
        n++;
    }
    printf("\n");
}

/*
 * Hàm tính và trả về giá trị của biểu thức ứng với giá trị của x
 */
double calculatePolynomialValue(struct Node *head, double x)
{
    double value = 0;
    while (head != NULL)
    {
        value += head->heSo * pow(x, head->soMu);
        head = head->next;
    }
    return value;
}

/*
 * Thêm phần tử vào cuối danh sách
 * tham số vào gồm con trỏ ở cuối danh sách để đỡ phải duyệt
 * và con trỏ newEle trỏ tới phần tử mới được thêm
 */
void addElementLast(struct Node **pHead, struct Node **pLast, struct Node *newEle)
{
    if (*pLast == NULL)
    { // danh sách đang rỗng
        *pLast = newEle;
        *pHead = newEle;
    }
    else
    { // danh sách khác rỗng
        (*pLast)->next = newEle;
        (*pLast) = (*pLast)->next;
    }
}
void insertNode(struct Node **head, struct Node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/**
* Hàm cộng đa thức và trả về đa thức tổng qua tên hàm (first + second)
 đa thức đầu vào là first và second KHÔNG được thay đổi
*/
struct Node *addPolynomial(struct Node *first, struct Node *second)
{
    // SINH VIÊN CODE TẠI ĐÂY
    struct Node *result = createNewNode(0, 0);
    struct Node *pnew = NULL;
    struct Node *preFirst = NULL;
    preFirst = result;
    while (first != NULL && second != NULL)
    {
        if (first->soMu > second->soMu)
        {
            pnew = copyNode(first);
            result->next = pnew;
            result = pnew;
            first = first->next;
        }
        else if (first->soMu == second->soMu)
        {
            struct Node *sum = NULL;
            if (first->heSo + second->heSo != 0)
            {
                sum = copyNode(first);
                sum->heSo = first->heSo + second->heSo;
            }
            result->next = sum;
            result = sum;
            first = first->next;
            second = second->next;
        }
        else
        {
            pnew = copyNode(second);
            result->next = pnew;
            result = pnew;
            second = second->next;
        }
    }
    struct Node *temp = preFirst;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (second != NULL)
        while (second != NULL)
        {
            pnew = copyNode(second);
            temp->next = pnew;
            temp = pnew;
            second = second->next;
        }
    if (first != NULL)
        while (first != NULL)
        {
            pnew = copyNode(first);
            temp->next = pnew;
            temp = pnew;
            first = first->next;
        }
    preFirst = preFirst->next;
    return preFirst;
}

/**
 * Hàm cộng giá trị đa thức second vào đa thức target
 */
void addPolynomialToCurrentPlynomial(struct Node **target, struct Node *second)
{
    struct Node *first = *target, *preFirst = NULL;
    struct Node *pNew = NULL;

    while (first != NULL && second != NULL)
    {
        // Nếu số mũ của đa thức 1 lớn hơn
        if (first->soMu > second->soMu)
        {
            preFirst = first;
            first = first->next;
        }
        else if (first->soMu == second->soMu)
        { // nếu số mũ bằng nhau
            if (first->heSo + second->heSo != 0)
            {
                first->heSo = first->heSo + second->heSo;
            }
            preFirst = first;
            first = first->next;
            second = second->next;
        }
        else
        { // ngược lại, số mũ đa thức 1 hiện tại nhỏ hơn
            pNew = copyNode(second);
            second = second->next;
            if (preFirst != NULL)
            { // thêm vào sau preFirst
                pNew->next = first;
                preFirst->next = pNew;
                preFirst = pNew;
            }
            else
            { // thêm vào trước phần tử đầu đa thức 1 nếu nó đang nhỏ hơn
                pNew->next = *target;
                *target = pNew;
                preFirst = pNew;
            }
        }
    }

    // thêm nốt các phần tử còn lại của đa thức 2 vào
    if (first == NULL)
    {
        first = preFirst;
    }
    while (second != NULL)
    {
        pNew = copyNode(second);
        second = second->next;

        // nếu danh sách ban đầu rỗng
        if (*target == NULL)
        {
            *target = pNew;
            first = pNew;
        }
        else
        {
            first->next = pNew;
            first = first->next;
        }
    }
}

/*
* Hàm trừ 2 đa thức và trả về đa thức hiệu qua tên hàm (first - second)
 đa thức đầu vào là first và second KHÔNG được thay đổi
*/
struct Node *subtractPolynomial(struct Node *first, struct Node *second)
{
    // SINH VIÊN CODE TẠI ĐÂY
    struct Node *pnew = NULL;
    struct Node *se2 = NULL;
    struct Node *res = NULL;

    pnew = createNewNode(0, 0);
    res = pnew;
    while (second != NULL)
    {
        se2 = copyNode(second);
        se2->heSo = -se2->heSo;
        pnew->next = se2;
        pnew = se2;
        second = second->next;
    }
    res = res->next;
    struct Node *result = addPolynomial(first, res);
    return result;
}

/*
 * Hàm nhân đa thức với 1 giá trị dạng a x ^b
 * Hàm trả về tích qua tên hàm
 */
struct Node *multiplyPolynomialWithNode(struct Node *head, struct Node *multiplier)
{
    // SINH VIÊN CODE TẠI ĐÂY
    struct Node *pnew = NULL;
    struct Node *se2 = NULL;
    struct Node *result = NULL;

    pnew = createNewNode(0, 0);
    result = pnew;
    while (head != NULL)
    {
        se2 = copyNode(head);
        pnew->next = se2;
        pnew = se2;
        head = head->next;
    }
    result = result->next;
    struct Node *temp = result;

    while (result != NULL)
    {
        result->heSo = result->heSo * multiplier->heSo;
        result->soMu = result->soMu + multiplier->soMu;
        result = result->next;
    }
    return temp;
}

/*
 * Hàm giải phóng bộ nhớ của đa thức
 */
void freePolynomial(struct Node **head)
{
    struct Node *curNode = NULL;
    while (*head != NULL)
    {
        curNode = *head;
        *head = (*head)->next;
        free(curNode);
    }
}

/**
 * Hàm nhân 2 đa thức bằng cách nhân từng số hạng rồi cộng dồn
 * Đa thức kết quả là đa thức mới trả về qua tên hàm
 */
struct Node *multiplyTwoPolynomial(struct Node *first, struct Node *second)
{
    // SINH VIÊN CODE TẠI ĐÂY
    struct Node *result = NULL;
    result = multiplyPolynomialWithNode(first, second);
    second = second->next;
    while (second != NULL)
    {
        result = addPolynomial(result, multiplyPolynomialWithNode(first, second));
        second = second->next;
    }
    return result;
}

/*
Test code
*/
int main()
{
    char nextCommand[100];
    int polyIndex;
    struct Node *hPoly1 = NULL, *hPoly2 = NULL, *hPoly3, *aNode;
    double x, heSo;
    int soMu;
    hPoly2 = readData();
    while (1)
    {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (strlen(nextCommand) == 0)
            continue;
        if (nextCommand[0] != '?')
            break;
        if (strcmp(&nextCommand[2], "readPolynomialExpression") == 0)
        {
            scanf("%d", &polyIndex);
            if (polyIndex == 1)
            {
                hPoly1 = readData();
            }
            else
            {
                hPoly2 = readData();
            }
        }
        else if (strcmp(&nextCommand[2], "printPolynomial") == 0)
        {
            scanf("%d", &polyIndex);
            if (polyIndex == 1)
            {
                printData(hPoly1);
            }
            else
            {
                printData(hPoly2);
            }
        }
        else if (strcmp(&nextCommand[2], "calculatePolynomialValue") == 0)
        {
            scanf("%d", &polyIndex);
            scanf("%lf", &x);
            if (polyIndex == 1)
            {
                printf("Value of Polynomial at x= %.2lf is %.2lf\n", x, calculatePolynomialValue(hPoly1, x));
            }
            else
            {
                printf("Value of Polynomial at x= %.2lf is %.2lf\n", x, calculatePolynomialValue(hPoly2, x));
            }
        }
        else if (strcmp(&nextCommand[2], "addTwoPolynomial") == 0)
        {
            hPoly3 = addPolynomial(hPoly1, hPoly2);
            printData(hPoly3);
            freePolynomial(&hPoly3);
        }
        else if (strcmp(&nextCommand[2], "subtractTwoPolynomial") == 0)
        {
            hPoly3 = subtractPolynomial(hPoly1, hPoly2);
            printData(hPoly3);
            freePolynomial(&hPoly3);
        }
        else if (strcmp(&nextCommand[2], "multiplyTwoPolynomial") == 0)
        {
            hPoly3 = multiplyTwoPolynomial(hPoly1, hPoly2);
            printData(hPoly3);
            freePolynomial(&hPoly3);
        }
        else if (strcmp(&nextCommand[2], "multiplyPolynomialWithOperand") == 0)
        {
            scanf("%lf%d", &heSo, &soMu);
            aNode = createNewNode(heSo, soMu);
            hPoly3 = multiplyPolynomialWithNode(hPoly1, aNode);
            printData(hPoly3);
            freePolynomial(&hPoly3);
            freePolynomial(&aNode);
        }
    }

    freePolynomial(&hPoly1);
    freePolynomial(&hPoly2);
    return 0;
}
