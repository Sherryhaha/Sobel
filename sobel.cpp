//
// Created by sunguoyan on 16/4/5.
//
#include"sobel.h"

/**
 * 功能：对图像进行二值化
 * 参数：src为原始图像，dst为处理后的图像，k为阈值
 */
void Sobel::ToTwoValue(Mat src,Mat dst,int K){
    int h,w;
    for(h = 0;h<Y_image;h++){
        for(w=0;w<X_image;w++){
            if(src.at<ty>(h,w) >=K){
                dst.at<ty>(h,w)=255;
            }
            else{
                dst.at<ty>(h,w)=0;
            }
        }
    }
}

/**
 *功能：判断当前邻域中心在邻域中的排序位置，并决定是否保留
 * 参数：src为目标图像，x,y为当前采样窗口中心像素的坐标，k为阈值
 */
bool Sobel::IsOnePoint(Mat src,int x,int y,int K){
    int i,j,k;
    int px,py,tmp;
    tmp = src.at<ty>(y,x);
    k = 0;
    for(i = 0;i < 3;i++){
        for(j = 0;j<3;j++){
            py = y-1+i;
            px = x-1+j;
            if(src.at<ty>(py,px) > tmp){
                k++;
            }
        }
    }
    if(k<K){
        return false;
    }
    else{
        return true;
    }
}

/**
 *功能：对图像进行单点化处理
 * 参数：src为原始图像，dst为处理的结果图像，k为阈值
 */
void Sobel::ToOnePointWide(Mat src,Mat dst,int K){
    int h,w;

    for(h = 1;h < Y_image - 1;h++){
        for(w = 1;w < X_image - 1;w++){
            if(IsOnePoint(src,w,h,K)){
//                dst.at<ty>(h,w) = src.at<ty>(h,w);
                dst.at<ty>(h,w) = 255;
            }
            else{
                //如果不是单点，在图中用白色标志
                dst.at<ty>(h,w) = 0;
            }
        }
    }
}

int main(){

    Mat src,dst,dst1;
    string filename="/Users/sunguoyan/Downloads/picture/heben.jpg";
    src = imread(filename,CV_LOAD_IMAGE_GRAYSCALE);
    dst.create(src.size(),src.type());
    dst1.create(src.size(),src.type());
    int k = 2;
    int k1 = 180;
    Sobel p;
    p.Y_image = src.rows;
    p.X_image = src.cols;

    p.ToTwoValue(src,dst1,k1);
    p.ToOnePointWide(dst1,dst,k);

    namedWindow("result");
    namedWindow("twovalue_result");
    imshow("twovalue_result",dst1);
    imshow("result",dst);
    waitKey(0);
    return 0;
}