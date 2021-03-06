#ifndef PLAYER_H
#define PLAYER_H

//#include <QtCore>
#include "tools.h"


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect/objdetect.hpp>
using namespace cv;
using namespace std;
class  VideoSrc{

public:
    bool video_connected_flag;
    VideoSrc(string path):p_cap(NULL)
    {

        video_connected_flag=true;
        memset(url,0,Tools::PATH_LENGTH);
       strcpy(url,path.data());

        p_cap= cvCreateFileCapture(url);  //create video source
        if(!p_cap)
           {
                prt(info,"fail to create");
               exit(1);
        }
        width=cvGetCaptureProperty(p_cap,CV_CAP_PROP_FRAME_WIDTH);
        height=cvGetCaptureProperty(p_cap,CV_CAP_PROP_FRAME_HEIGHT);
        //    prt(info,"video widtbh %d  ",ret);
        if(p_cap==NULL){
            prt(info,"video src start  %s err  ",url);
            video_connected_flag=false;
        }
        else {
            prt(info,"video src  start %s ok  ",url);
        }
        //        if(p_cap==NULL)
        //            emit video_disconnected();
        //        else
        //            emit video_connected();




        //    timer=new QTimer();
        //  tmr->singleShot(1000,this,SLOT(time_up()));

        //    prt(info," shot afer 100 ms")
        // QTimer::singleShot(1000,this,SLOT(time_up()));
        //   connect(timer,SIGNAL(timeout()),this,SLOT(time_up()));
        //   timer->start(wait_duration);
    }
    ~VideoSrc()
    {
        //   cap_lock.lock();
        // timer->stop();
        //  disconnect(timer,SIGNAL(timeout()),this,SLOT(time_up()));
        //   delete timer;
        //     QThread::sleep(1);
        //   prt(info," delete src");
        //    disconnect(tmr,SIGNAL(timeout()),this,SLOT(time_up()));
        cvReleaseCapture(&p_cap);
        p_cap=NULL;
        //    cap_lock.unlock();
        //   delete tmr;
        //   delete p_cap;
    }
    Mat *get_frame()
    {

        //     tmr->singleShot(10,this,SLOT(time_up()));
        int err=0;
        if(p_cap==NULL){
            video_connected_flag=false;
            err=1;
            //   emit video_disconnected();
        }
        IplImage *ret_img;

        //            prt(info,"try to grb");
        //        int tmp= cvGrabFrame(p_cap);
        //             prt(info,"grub source url:%s ret %d (%p)",url,tmp,p_cap);
        //        ret_img= cvRetrieveFrame(p_cap);
        //   prt(info,"try to query");
        //    CV_CAP_PROP_XI_TIMEOUT
        //CV_CAP_PROP_FRAME_WIDTH
        //    int ret=cvSetCaptureProperty(p_cap,CV_CAP_PROP_XI_TIMEOUT,999);
        // double pro=cvGetCaptureProperty(p_cap,CV_CAP_PROP_XI_TIMEOUT);
        //  prt(info," set %d ,opecv time out %d",ret ,pro);
        //      CV_CAP_PROP_XI_TIMEOUT
        //prt(info,"  start query 1 frame ");
        ret_img=cvQueryFrame(p_cap);
        Mat(ret_img).copyTo(mat_rst);
        if(ret_img==NULL){
            err=1;
            //     std::this_thread::sleep_for(chrono::milliseconds(1000));
            //    QThread::sleep(1);
            if(video_connected_flag==true)
            {
                //    prt(info,"%s disconnected",url);
                video_connected_flag=false;
            }
        }else{
            if(video_connected_flag==false)
            {
                //     prt(info,"%s connected",url);
                video_connected_flag=true;
            }
        }
        if(err)
            return NULL;
        else
            return &mat_rst;

    }
    char *get_url(){
        return url;
    }

private:
    CvCapture *p_cap;
    char url[Tools::PATH_LENGTH];
    int width;
    int height;
    Mat mat_rst;
};
using namespace cv;
using namespace std;

class VideoHandler{
        string cas_url;
public:
    IplImage * frame_ori;

    VideoHandler()
    {
        cas_url.clear();
   //     namedWindow("123", CV_WINDOW_NORMAL);
    }
    VideoHandler(string url)
    {
             cas_url.clear();
cas_url=url;
    }
    ~VideoHandler()
    {

    }
    void set_frame( Mat * frame)
    {
        frame_mat=frame;
    }
    void set_null_frame( )
    {
        Mat frame;
        frame.resize(0);
        frame_mat=&frame;
    }
    //  bool work(QByteArray &rst_ba)
    bool work()
    {
     //   QByteArray rst_ba;
        int min_win_width = 64;	// 48, 64, 96, 128, 160, 192, 224
        int max_win_width = 256;
        bool ret=false;
        CascadeClassifier cascade;
        vector<Rect> objs;
        //string cascade_name = "../Hog_Adaboost_Pedestrian_Detect\\hogcascade_pedestrians.xml";
        // string cascade_name = "/root/hogcascade_pedestrians.xml";

      //  const string cascade_name = "/root/repo-github/pedestrian-v12/server/hogcascade_pedestrians.xml";
        string    cascade_name;
        if(cas_url.size()>0){
                  cascade_name =cas_url;
        }else{
            cascade_name = "D:/hogcascade_pedestrians.xml";
}
        if (!cascade.load(cascade_name))
        {
            prt(info,"can't load cascade");
            // cout << "can't load cascade!" << endl;
            //return -1;
        }
#if 1

        // while (1)
        {
            //   frame_ori = cvQueryFrame(p_cap);
            //   frame.create(frame_ori->height,frame_ori->width,CV_8U);
            //   memcpy(frame.data,frame_ori->imageData,frame_ori->imageSize);
            // Mat frame(frame_ori);


            // int test=  waitKey(1);
            //     printf("%d\n",test);
            Mat frame(*frame_mat);
          //  cv::namedWindow("1111")
            prt(info,"showing");
           // namedWindow("url");

//            cv::namedWindow("url", CV_WINDOW_NORMAL);

//            cv::namedWindow("camera1", CV_WINDOW_NORMAL);
//            while(1);
            string str("123");
            if(!frame.empty())
             imshow(str,frame);
            waitKey(1);
            //  return true;
        //     waitKey(25);
            //    QThread::msleep(1);

            //   return 0;
            if (!frame.empty())
            {
                frame_num++;
                if (frame_num % 100 == 0)
                {
                    cout << "Processed " << frame_num << " frames!" << endl;
                }

                //   if (frame_num % 3 == 0)
                if (1)
                {
                    resize(frame,frame,Size(frame.cols / 2, frame.rows / 2),CV_INTER_LINEAR);
                    //resize(frame,frame,Size(704, 576),CV_INTER_LINEAR);
                    cvtColor(frame, gray_frame, CV_BGR2GRAY);
                    //  gray_frame=frame;
                    //Rect rect;
                    //rect.x = 275;
                    //rect.y = 325;
                    //rect.width = 600;
                    //rect.height = 215;

                    //Mat detect_area = gray_frame(rect);
                    //cascade.detectMultiScale(detect_area,objs,1.1,3);
                    cascade.detectMultiScale(gray_frame, objs, 1.1, 3);


                    vector<Rect>::iterator it = objs.begin();
                    while (it != objs.end() && objs.size() != 0)
                    {
                        pedestrian_num++;
                        pedestrians = frame(*it);

                        Rect rct = *it;
                        if (rct.width >= min_win_width && rct.width < max_win_width)
                        {
                            //   sprintf(file_name, "%d.jpg", pedestrian_num);
                            //  imwrite(file_name, pedestrians);

                            //rct.x += rect.x;
                            //rct.y += rect.y;

                            int test=12345;
                            rectangle(frame, rct, Scalar(0, 255, 0), 2);

//                            QString x_str=QString::number(rct.x);
//                            QString y_str=QString::number(rct.y);
//                            QString test_str=QString::number(test);

//                            rst_ba.append(x_str.toStdString().data());
//                            rst_ba.append(",");
//                            rst_ba.append(y_str.toStdString().data());
                            //prt(info,"%d %d",rct.x,rct.y);

                            ret=true;
                            break;//TODO, now we get first one
                        }

                        //  rst_ba.append(";");
                        //  rst_ba.append(rct.x);
                        it++;
                    }
#if 0
                    imshow("result", frame);
                    QThread::msleep(1);


#endif
                    //                    waitKey(1);

                    //   rectangle(frame,rect,Scalar(0,255,0),2);
                 //   imshow("result", frame);
                    //outputVideo << frame;
                    //   waitKey(1);
                    objs.clear();
                }
            }
            else
            {
                prt(info,"opencv handle frame error !");
            }
        }
#endif
        if(ret==true){
            //   emit send_rst(rst_ba);
        }
        return ret;
    }


private:
    Mat gray_frame;
    Mat pedestrians;
    Mat *frame_mat;
  //  QList <Mat> frame_list;
    int pedestrian_num = 0;
    int frame_num = 0;

};

class Player
{
public:
    Player();
};

#endif // PLAYER_H
