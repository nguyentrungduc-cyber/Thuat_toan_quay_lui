// Bai1: Nhập n số nguyên và hiện ra các trường hợp n bit
// vd: n = 3, 000 001 010 ...

#include <iostream>

// Hàm in mảng
void xuatMang(int X[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        std::cout << X[i];
    }
    // Hết một phần tử i bit thì xuống dòng
    std::cout << std::endl;
}

// Hàm hiện các trường hợp i bit của mảng X với n phần tử, i chạy từ 1 đến n - từ bit đầu đến bit cuối, các bit lần lượt thay đổi giá trị do j
void Try(int i, int X[], int n)
{
    // duyệt từ khả năng 1 đến M khả năng, tức là 1 bit thì có thể là 0 hoặc 1
    for (int j = 0; j <= 1; j++)
    {
        // Hàm if: điều kiện để chấp nhận các khả năng j, nhưng trong bài này không cần
        // Nếu đáp ứng điều kiện if thì gán khả năng j vào ..., có thể là mảng, trong bài này là mảng X với i bit
        X[i] = j; // vì mảng gồm các phần tử i bit, vd nếu đầu vào i = 1 thì bit đầu là 0
        // Hàm if lồng: kiểm tra i == n để xuất các giá trị tìm được, ở đây là các phần tử i bit
        if (i == n)
        {
            xuatMang(X, n); // chỉ xuất khi mảng chạm tới giá trị cuối cùng, trong bài này là bit lớn nhất X[3]
        }
        else
        {
            Try(i + 1, X, n); // chuyển qua bit tiếp theo;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    int X[n];
    Try(1, X, n);
    return 0;
}