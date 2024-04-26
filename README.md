# **THE DODGE WITCH - UET K68J**



# GAME INTRODUCTION
The dodge witch là một game thuộc thể loạt platformer đánh quái ,né tránh đòn tấn công ,ăn vật phẩm và di chuyển đến điểm cuối cùng của map để chiến thắng .Với câu chuyện kể về một vị pháp sư bị đánh cắp đi rương báu vật của mình cùng với sự chỉ dẫn của vị pháp sư tập sự ,pháp sư phải sử dụng kĩ năng cầu năng lượng và khả năng tránh né của mình để thu thập lại kho báu rơi trên đường nhằm tiến đến lấy lại rương báu vật mà bản thân bị đánh cắp.
Game này được lấy cảm hứng cũng như là được tham khảo từ series SDL2 C++ của youtuber phát triền phần mềm 123AZ:https://www.youtube.com/watch?v=q1WzniyeGTU&list=PLR7NDiX0QsfTIEQUeYCfc2MyCquX0ig9V

# 1.GAMES START
[background](tham khảo trên mạng):(![wizard0](https://hackmd.io/_uploads/rJmPYkdZC.jpg)
)
Để bắt đầu trò chơi kích chuột trái vào màn hình menu có chứ "press to start " để vào game.
# 2.GAME COMPONENTS
**a) nhân vật ** THE WITCH **:**
![l](https://hackmd.io/_uploads/SkQK5J_b0.png)
Là một vị phù thủy già sống trong rừng sâu có rất nhiều của cải và các báu vật có khả năng né tránh điêu luyện và bắn cầu năng lượng. Là nhân vật chính để ngươì chơi điều khiển.
**b) nhân vật ** THE APPERENTICE **:**
![Idle9](https://hackmd.io/_uploads/rJRy21dWC.png)

Đây là học trò của phù thủy tình cớ chứng kiến được vụ mất cắp kho báu của thầy mình.Vì thế dù chứng kiến thế nhưng không thể làm được gì giúp thầy mình ngoài đưa ra các chỉ dẫn. Nhân vật này là 1 NPC xuất hiện lúc ban đầu của game giúp kể lại câu chuyển và chỉ cách chơi cho người chơi.
**c) nhân vật ** THE FLOATING PUMPKIN **:**
![threats_right](https://hackmd.io/_uploads/rkWLpyOWC.png)
Một con quái vật được sinh ra từ sự tham lam của con người cùng với sự ảnh hưởng của ma thuật trong môi trường tự nhiên .Tên trộm đã thức tỉnh con quái vật này hoạt động và có năng lực di chuyển gây ra những va chạm choáng làm ảnh hưởng đến những vật thể mà vô tính chạm vào chúng.Đây là một dạng quái vật mà người chơi phải tránh né khỏi tầm hoạt động hoặc đánh bại chúng.
**d) nhân vật ** THE CLONE **:**
![threat1](https://hackmd.io/_uploads/HJmC01ObR.png)
Tên trộm ranh mãnh không những học lỏm được tuyệt chiêu bán chưởng của phù thủy mà còn tự phát triển cho bản thân khả năng phân thân nhằm cản đường phù thủy suốt dọc đường.Đây là một dạng quái vật nữa tuy không có khả năng di chuyển bù vào đó nó lại bắn được những quả cầu gây sát thương yêu cầu người chơi phải tránh né đồng thời đánh bại chúng.
**e) các thành phần tạo map ** ASSETS **:**
*TILES MAP:
![2](https://hackmd.io/_uploads/SJHfbgO-R.png)
![3](https://hackmd.io/_uploads/S1K7WgdWR.png)
*MAIN BACK GROUND:
![background_layer_1](https://hackmd.io/_uploads/Bye_We_W0.png)
![background_layer_2](https://hackmd.io/_uploads/rJI_WgOW0.png)
![background_layer_3](https://hackmd.io/_uploads/HyYuWg_ZA.png)
*RUBY:
![6](https://hackmd.io/_uploads/HJU6Wgd-0.png)
*HEART:
![Icon12](https://hackmd.io/_uploads/rJzkGgO-0.png)
*BULLET:
![bullet](https://hackmd.io/_uploads/HkLefl_ZR.png)
# 3.GAME PLAY
  Khi bắt đầu game người chơi có thể đến gặp NPC là phủ thủy tập sự ở đầu map để hỏi chuyện.Bấm "K" để có thể tương tác với nhân vật này .
  Cách chơi:
  Đây là một game platformer cơ bản dùng đầu vào là các phím mũi tên trên bàn phím để di chuyển và nhảy .Sử dụng chuột vào làm đầu để bắn và điều chỉnh các thao tác.
  Người chơi sẽ phải vận dụng sự nhanh tay đồng thời khả năng phán đoán để né tránh các chướng ngại vật đồng thời đánh bại các quái vật trên đường đi.Khi đụng vào quái vật hoặc khi bị đạn quái vật bắn người chơi sẽ bị trừ mạng và sau 3 mạng thì trò chơi sẽ kết thúc rồi mạng hình sẽ hiện ra một message box 
có tiêu đề "Game Over".Khi đi đến cuối map và chạm vào thùng châu báu thì người chơi sẽ thắng và đó cũng là lúc mà game này kết thúc.
# 4.TOOLS
   - Kĩ thuật đồ họa với SDL2
   - Con trỏ, hàm,class
   - Vector
   - Load ảnh PNG
   - Đồ họa chủ yếu tìm trên itch.io và các sprite sheet maker web:https://itch.io/game-assets/tag-characters/tag-wizards
   - Ngôn ngữ C
   - kênh youtube phát triển phần mêm 123AZ
   - Web Lazyfool:https://lazyfoo.net/tutorials/SDL/index.php
   - Các kĩ thuật lập trình cơ bản
   
# 5.ABOUT CODE GAME
  - Các file cơ bản:
  + Baseobject : là class chung để khởi tạo cho các đối tượng khác
  + main.cpp : là file tổng hợp các nguồn để chạy và khai báo nhiều phần khác như là text,menu,..
  + MainOject.cpp : là file xử lý nhân vật chính
  + NPC.cpp : file xử lý nhân vật NPC
  + Threats.cpp : file xử lý các quái vật bao gồm cả 2 loại đứng yên và chuyển động
  + IMP.cpp : xử lý độ trễ của game
  + BulletObject.cpp : xử lý đạn
  + game_map.cpp : xử lý map
  + CommonFunc.cpp : xử lý các tác vụ cơ bản bao gồm cả kiểm tra va chạm
