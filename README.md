# **THE DODGE WITCH - UET K68J**

Tên : Lê Trí Đăng 

MSSV : 23020659


# GAME INTRODUCTION
The dodge witch là một game thuộc thể loạt platformer đánh quái ,né tránh đòn tấn công ,ăn vật phẩm và di chuyển đến điểm cuối cùng của map để chiến thắng .Với câu chuyện kể về một vị pháp sư bị đánh cắp đi rương báu vật của mình cùng với sự chỉ dẫn của vị pháp sư tập sự ,pháp sư phải sử dụng kĩ năng cầu năng lượng và khả năng tránh né của mình để thu thập lại kho báu rơi trên đường nhằm tiến đến lấy lại rương báu vật mà bản thân bị đánh cắp.
Game này được lấy cảm hứng cũng như là được tham khảo từ series SDL2 C++ của youtuber phát triền phần mềm 123AZ:https://www.youtube.com/watch?v=q1WzniyeGTU&list=PLR7NDiX0QsfTIEQUeYCfc2MyCquX0ig9V

# 1.GAMES START
[background](tham khảo trên mạng):
)![wizard0](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/aabfe569-79b0-45ae-8bf6-c1b93d7c0c52)

Để bắt đầu trò chơi kích chuột trái vào màn hình menu có chứ "press to start " để vào game.
# 2.GAME COMPONENTS

**a) nhân vật ** THE WITCH **:**
![r](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/beb6eb1c-2516-4c5f-9ec2-a79a09f650ed)


Là một vị phù thủy già sống trong rừng sâu có rất nhiều của cải và các báu vật có khả năng né tránh điêu luyện và bắn cầu năng lượng. Là nhân vật chính để ngươì chơi điều khiển.

**b) nhân vật ** THE APPERENTICE **:**
![Idle9](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/616dbfc4-1c7d-46fb-8a30-7b0f31660155)


Đây là học trò của phù thủy tình cớ chứng kiến được vụ mất cắp kho báu của thầy mình.Vì thế dù chứng kiến thế nhưng không thể làm được gì giúp thầy mình ngoài đưa ra các chỉ dẫn. Nhân vật này là 1 NPC xuất hiện lúc ban đầu của game giúp kể lại câu chuyển và chỉ cách chơi cho người chơi.

**c) nhân vật ** THE FLOATING PUMPKIN **:**
![threats_left](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/ef48b21c-8577-4306-bbb1-cdedc1d329d6)


Một con quái vật được sinh ra từ sự tham lam của con người cùng với sự ảnh hưởng của ma thuật trong môi trường tự nhiên .Tên trộm đã thức tỉnh con quái vật này hoạt động và có năng lực di chuyển gây ra những va chạm choáng làm ảnh hưởng đến những vật thể mà vô tính chạm vào chúng.Đây là một dạng quái vật mà người chơi phải tránh né khỏi tầm hoạt động hoặc đánh bại chúng.

**d) nhân vật ** THE CLONE **:**
![threat1](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/88c82579-beb7-4c5e-bdb3-bc02fbcae2b1)


Tên trộm ranh mãnh không những học lỏm được tuyệt chiêu bán chưởng của phù thủy mà còn tự phát triển cho bản thân khả năng phân thân nhằm cản đường phù thủy suốt dọc đường.Đây là một dạng quái vật nữa tuy không có khả năng di chuyển bù vào đó nó lại bắn được những quả cầu gây sát thương yêu cầu người chơi phải tránh né đồng thời đánh bại chúng.

**e) các thành phần tạo map ** ASSETS **:**

*TILES MAP:

![3](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/cbd3493d-111a-4631-a732-3639e76724d1)
![2](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/dd36126a-1846-4dc0-9ce8-b2f07b25c66b)


*MAIN BACK GROUND:

![background_layer_1](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/06aec338-3380-4955-9081-943c447e873b)

![background_layer_2](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/aa40bcee-399c-4e66-a929-5b45631b0a93)

![background_layer_3](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/d61ddb8a-7778-4438-bbc2-cea1feff1811)

*RUBY:
![6](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/6d6ae31f-0f2b-4670-aa92-6eb7f50e94c6)


*BULLET:
![bullet](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/b464916d-62e8-4bfa-b12d-39d3b170ea13)

*CHEST:
![5](https://github.com/dang0801205/btl-l-tr-ng/assets/148788265/bed304a2-ccbf-42bb-a745-c633ebe79bde)


# 3.GAME PLAY

  Khi bắt đầu game người chơi có thể đến gặp NPC là phủ thủy tập sự ở đầu map để hỏi chuyện.Bấm "K" để có thể tương tác với nhân vật này .
  
  Cách chơi:
  
  Đây là một game platformer cơ bản dùng đầu vào là các phím mũi tên trên bàn phím để di chuyển và nhảy .Sử dụng chuột vào làm đầu để bắn và điều chỉnh các thao tác.
  
  Người chơi sẽ phải vận dụng sự nhanh tay đồng thời khả năng phán đoán để né tránh các chướng ngại vật đồng thời đánh bại các quái vật trên đường đi.Khi đụng vào quái
  vật hoặc khi bị đạn quái vật bắn người chơi sẽ bị trừ mạng và sau 3 mạng thì trò chơi sẽ kết thúc rồi mạng hình sẽ hiện ra một message box 
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
