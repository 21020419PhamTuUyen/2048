# 2048
1. hướng dẫn cài đặt:
  - clone từ git về vs code
  - ở phần terminal gõ lệnh 'make' và './main.exe'
2. mô tả:
  về game 2048, là một loại game cổ điển mà trong đó người chơi sẽ di chuyển các ô số (bắt đầu từ 2), các ô có số giống nhau sẽ cộng dồn lên, nhiệm vụ của ngừoi chơi là di chuyển sao cho các ô só cộng dồn được đến 2048. Game sẽ kết thúc nếu các ô số đã bịt kín các ô trong bảng và không thể di chuyển các ô số được nữa.
3. các chúc năng có trong game:
  a. về phần menu game:
    - menu cơ bản có 2 nút là new game và score
    - có hiệu ứng và âm thanh khi chuột di chuyển vào và bấm vào các nút
  b. về phần new game:
    - trước khi vào game người chơi sẽ được nhập tên của mình để luu thồng tin cho phần score, nếu người chơi để tên rỗng thì sẽ tự động được lưu là 'player'
    - phần nhập tên có nút 'back' và nút 'enter', nếu bấm vào nút 'back' sẽ được đưa trở về phần menu. Còn nếu bấm vào nút 'enter' hoặc nhấn enter người chơi sẽ được đưa vào phần game
    - hướng dẫn chơi: sử dụng các nút awds để di chuyển các ô số mỗi khi ô số giống nhau thì sẽ được cộng dồn
    - trong phần game cũng có nút 'back' để trở lại menu, nếu người chơi bấm thoát ra hoặc trở lại trong quá trình này game sẽ lưu lại điểm hiện tại của người chơi và được sắp xếp theo thứ tự điểm trong file 'score_list.txt'
    - trong các quá trình trên các nút bấm và di chuyển các ô số đều có âm thanh
  c. về phần score:
    - là bảng xếp hàng top 10 người có điểm số cao nhất được xếp theo thứ tự từ cao xuống thấp.
   --->video minh họa: 
4. các kĩ thuật được sủ dụng:
  - một số thao tác của SDL cơ bản, có renderer vẽ nhưng thử cơ bản(nút bấm, ô số,...., có load hình ảnh (tiêu đề của game ở phần menu), có âm thanh (các nút bấm), có chính sửa về máu sắc sủ dụng (SDL_MapRGB), màu của các ô số đậm dần theo các số ở trên ô sô, có load texture theo kiểu bitmap (không cần sử dụng đên SDL_tff vẫn có thể vẽ được chữ và chỉnh font chữ) 
  - có chia file (theo chức năng)
  - có cấu trúc class đơn giản (phần player, và nút bấm)
  - sử dụng mảng con trỏ 
  - các thuật toán để vẽ bảng, các ô số, thuật toán để di chuyển và cộng dồn các ô số
5. kết luận
  - em đã tìm hiểu và tiếp thu kiến thức về SDL2 tại:[ lazyfoo.net/tutorials/SDL/](https://lazyfoo.net/tutorials/SDL/)
  - tham khảo cách thức hoạt động của game từ nhiều nguồn trên mạng
  - tự code và thiết kế game
  - về hướng phát triển: 
      + mở thêm chế độ game cho phép lựa chọn kích thước của bảng
      + có thêm chức năng cài đặt cho game
      + nâng cấp độ họa và animation cho game
  - kinh nghiệm rút ra:
      + được tìm hiểu và tự làm 1 game đơn giản
      + có kĩ năng cơ bản về tạo project nhỏ và lập trình trên vs code
      + thêm được một chút thông tin về cách sử dụng github
      + nhược điểm về lập trình hướng đối tượng (phần main còn khá dài do em chưa biết chia nhỏ đối tượng ra sao cho phù hợp)