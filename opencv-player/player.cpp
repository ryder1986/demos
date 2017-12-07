#include "player.h"
//using namespace cv;
Player::Player()
{
    VideoSrc *p_src=new VideoSrc("test.264");
    VideoHandler *p_han=new  VideoHandler("hogcascade_pedestrians.xml");
    Mat *mt;
    int flg=0;

   while(1){
    mt=p_src->get_frame();
    p_han->set_frame(mt);;
    p_han->work();
    if(flg++>20){
        delete p_src;
        delete p_han;
         p_src=new VideoSrc("test.264");
         p_han=new  VideoHandler("hogcascade_pedestrians.xml");
        flg=0;
         this_thread::sleep_for(chrono::milliseconds(100));
    }
  //  this_thread::sleep_for(chrono::milliseconds(3000));
    }
}

