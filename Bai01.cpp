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
    // Hết một phần tử i bit thì xuống dòng, vd: 000 xuống dòng rồi 001
    std::cout << std::endl;
}

// Hàm xử lý mảng gồm n phần tử, X[i] với i chạy từ 1 đến n - bit 1 đến bit n trong bài
void Try(int i, int X[], int n)
{
    // duyệt từ khả năng 1 đến M khả năng, tức là 1 bit thì có thể là 0 hoặc 1
    for (int j = 0; j <= 1; j++) // lưu ý dấu "="
    {
        // Hàm if mẹ: điều kiện để chấp nhận các khả năng j, nhưng trong bài này không cần
        // Nếu đáp ứng điều kiện if thì gán khả năng j vào ..., có thể là mảng X[i] tức trong bài là bit thứ i, i sẽ tăng dần
        X[i] = j; // vì mảng gồm các phần tử i bit, vd nếu đầu vào i = 1 thì bit đầu là 0
        // Hàm if con: kiểm tra i == n để xuất các giá trị tìm được
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

// Nguyên lý của thuật toán quay lui: sẽ xử lý giá trị xuất hiện cuối cùng rồi mới từ từ quay lại
// Như trong bài này:
// Ban đầu j = 0 thì X[1] = 0, ban đầu i = 1, tức bit đầu tiên sẽ bằng 0. Giả sử n = 3 thì lúc này phần từ đầu tiên của mảng X là 0_ _
// Tiếp là hàm if con, vì i mới là bit đầu nên hàm xuatMang() không hoạt động, đệ quy sang bit tiếp theo, bit số 2
// j vẫn bằng 0 nên phần tử đầu tiên của mảng X thay đổi là 00_
// Tiếp tục vẫn vậy, phần tử đầu tiên của mảng X thay đổi là 000, lúc này sau khi gán X[3] = j thì i là 3 đã bằng n, xuất phần tử đầu tiên 000
// Đệ quy của i = 3 vẫn còn j = 1, nên thay vì 000 thành 001, xuatMang() tiếp tục hoạt động
// Đệ quy của i = 3 đã xong, quay lại đệ quy của i = 2 giống như Stack vậy
// Lúc này, hàm for j = 0 đã hoàn thành nhiệm vụ, qua j = 1, thì i vẫn là 2, tức bit số 2, 01_, chưa đủ điều kiện i == n, chuyển qua bit số 3
// Đệ quy của i = 3 như cũ, j = 0 010 và j = 1 011
// Lúc này đệ quy i = 3 đã xong, đệ quy i = 2 đã xong, quay lại đệ quy 1, j = 0 đã xong, tiếp lúc j = 1, quay lại lúc đầu, như j = 0 chỉ khác thay vì 0_ _ mà là 1_ _
