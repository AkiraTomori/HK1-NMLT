# HK1-NMLT
Đề: Xây dựng phần mềm quản lý thư viện cho HCMUS. Đồ án này có yêu cầu kỹ thuật là không được phép sử dụng struct và text files, ngoài ra không được sử dụng biến toàn cục (Global Variable) để thực hiện đồ án, chỉ được phép sử dụng những mảng dữ liệu đã được học (những kiến thức đã học từ đầu học phần cho đến tuần thứ 8-9 của học phần).
Xây dựng đồ án này theo hướng Top-down
1. MainMenu sẽ chứa các đơn thể độc lập với nhau
    + Reader: độc giả
    + Book: sách
    + Bookloan: phiếu mượn sách
    + Query/Statistic: Thống kê
    + GetData: Lấy dữ liệu (đọc files)
    => Chia tách ra và xử lý từng đơn thể một
2. Phân tích xem từng đơn thể nó có những công việc gì (theo yêu cầu đề bài của từng cái) và xây dựng bản thô trước.
3. Bắt tay vào code từng cái và kiểm tra nó hoạt động.
4. Hoàn tất code phiên bản đầu tiên.
5. Công việc quan trọng: DEBUG. (lúc đó bạn muốn gọi là phiên bản mấy cũng được: demo, alpha, beta, closed-beta, early-accessed gì đó tùy mọi người code)
6. Debug đến khi chương trình hoạt động ổn (đừng mong hoàn hảo chỉn chu mọi thứ quá, nên ở mức đủ là được).

Lời khuyên của mình đối với phiên bản này thì là chỉ nên code đủ tính năng theo yêu cầu và hoạt động ở mức cơ bản là được bởi vì việc không sử dụng struct để xử lý và lưu các thuộc tính của dữ liệu sẽ khiến cho việc code đồ án này rất là mệt vì bạn sẽ phải truyền rất là nhiều tham số và việc truyền như vậy đôi khi sẽ khiến bản thân bị rối và có thể dẫn đến việc debug đồ án này cũng khoai, vì thế mọi người cứ code mà hoạt động là được và sử dụng lại cái sườn của đồ án này để phát triển cho đồ án số 2 vì đồ án số 2 được sử dụng lại struct và cú pháp sẽ giúp bạn có phần dễ thở hơn trong việc code và debug, đồng thời bạn có thể phát triển những ý tưởng của bản thân tốt hơn.
Tất nhiên bạn vẫn có thể phát triển mở rông ở đồ án số 1 chỉ là công việc sẽ khá mệt hơn nên mình khuyên là làm ở mức vừa là được, đừng ép bản thân quá. Code khi học với làm khác nhiều lắm cho nên hãy coi đồ án này là một bài tập nhỏ để mình hình thành tư duy và thiết kế sau này.
Đồ án này sẽ có thời lượng là 8 tuần, mục đích là để tập làm quen các cú pháp của C++ và làm quen cách mà phân chia code ở các files, đồng thời áp dụng những kiến thức đang học ở học phần Nhập môn lập trình để thực hiện.