/************************************************************
Filename: Rectangle_Detection
Author: Wu Qichao
Version; 1_6_4
Date: 2017-05-03
Description:1)�Ը���ĺ˶�canny��Ե�������Ͳ�����kernel_coefficient3����Ȼ�������ľ����ں�ͼ���������ʱ�򣬰Ѿ������ϴ���쳤��expand_edge_coefficient��
Funtion List:
History:
1��Date:2017-04-07
Author:Wu Qichao
Version:1_0_0
Modification:�ο����ϵĳ���http://blog.csdn.net/mr_vision/article/details/4242904��������û���޸�
2��Date:2017-04-11
Author:Wu Qichao
Version:1_1_0
Modification:��ԭ����ֻ����2������(�ӵ�0�㿪ʼ)���޸�Ϊ��ÿһ����������⣻
��ԭ�����ó���ȱ�Ϊ����ռ�ձ������о��μ��
3��Date:2017-04-12
Author:Wu Qichao
Version:1_2_0
Modification:1)�޸���duty_cycle��ֵ
2)���Ե�ǰ�����Ƿ���v->next������λ�õ������Ƶ���ѭ����β��
3)��ChipInfo�ṹ����������С������min_rectangle_area��Ա���󣬲��޸���duty_cycle�ļ��㷽����ԭ���ļ��㷽������
4��Date: 2017-04-12
Author: Wu Qichao
Version; 1_2_1
Modification:��1_2_0�Ļ����������ע��
5��Date: 2017-04-23
Author: Wu Qichao
Version; 1_4_0
Modification:1)��canny�㷨��ȡ����
2)�����˻��������������canny�㷨����ֵ
3)�ڵ�0���������޸��˻����εķ���������cvRectangle�������л�ͼ������ԭ����0�������͵�1���������ǣ����µ�0������û����ʾ
4)���������ÿ��ղ�������̬ѧ����Ա�Ե��������
6��Date: 2017-04-24
Author: Wu Qichao
Version; 1_5_0
Modification:1)����Ԥ����Ҳ���Ǹ��ݲ��ű�Ե�Ǻ�ɫ���ɫ�������������ɫ��Ϣ���д������巽������cvCopy��Ĥ����
2)�޸�1Ч�����ã����ã��˻ص�1_4_0
6��Date: 2017-04-25
Author: Wu Qichao
Version; 1_6_0
Modification:1)�޸��˳����һ��С����Ҳ���Ǳղ���û�н��˵Ĵ�С����NULL�滻���Զ��Ե�element����
2)���þ����ںϵķ������Ͽ��������ں���һ��,����������������С���Σ�Ȼ������һ�������ͨ���Դﵽ��ͨ��Ŀ�ġ�Ȼ���ҳ�����ͨ��������Ӿ��Σ��������������ںϡ�
3)���ֵ�3��������һЩ���󣬲������޸�
4)���ε�width��height��ͳһ����������֪������Ӿ�����angle��ԭ��
6��Date: 2017-04-28
Author: Wu Qichao
Version; 1_6_1
Modification:1���㲻���ΪʲôcvDrawContours���ܽϺõ���������ڲ�������˷������ø÷������÷�����һ�������壬�ɼ������г��ԣ�����1_7_0�˻ص�1_6_0��
2����֮ǰ��canny��ȡ��Եͼ���бղ����Ļ����ϣ���������Ͳ��������ڼӴֱ�Ե
Others:�������룬��Ϊ��canny��ȡ��Եͼ��Ļ�������������Ͳ������Ա�Եͼ����������������һ������������������������һ������������ճ����һ���������ռ�⵽�ľ�������������������
�Ӷ�������һ�����⣬����һ����������򣬽��о����ڲ����֮�󣬻�ֳɺö��С���򡣴�ʱ���ɿ������������ʱ�򣬰Ѿ��ε���Χ��һȦ������Ҳ��䣬������ֵΪ�����ⲿkernel_coefficient3�����ȴ�С������
6��Date: 2017-05-02
Author: Wu Qichao
Version; 1_6_2
Modification:1����2017/5/2�յ����ݽ��в��ԣ��ļ�����Ϊsnap1
2��Ϊ�˶�ȡ���Է��㣬������ͼƬ��ȡ��ʽ�Ż�Ϊ������ȡ��ʽ
3������ں�ʱ��������һ�飬���Կ��ǰ����С�ľ����˵�����ֹ��Ϊ��Щ����ʹ����ص�����������һ��,ͨ���޸�contours_tatal_threshold��ʵ�ָ�Ŀ��
4�����ĳЩ�����ں�ͼ�У����ڵľ�����ĳЩ�㴦���������³�Ϊһ���������ͨ�򣨸���ͨ�����Ǿ�����״�������������ν����һ��Ĳ�������״��
�����µļ��ʧ�ܣ���ͨ���޸�kernel_coefficient2������ʹ��ʴ�ĳ̶ȸ�ǿ�ң��ж��������������Ĳ��֡�
7��Date: 2017-05-03
Author: Wu Qichao
Version; 1_6_3
Modification:1)���ֻ��⵽���ŵ�һ���ݶ�û�м������������㷨�ĸĽ���������canny��Եͼ�����Ͳ�����Ȼ��
���������ʱ�򣬰Ѿ������ϴ���쳤��������ֵΪ�����ⲿkernel_coefficient3�����ȴ�С����ʹ�ɻ����Ÿ��ѵľ�����������һƬ��
2)��Թ��ղ����ȵ��µ�canny��Ե��ȡ��ȱ�ڵ����⣬�ɿ���ͨ��ͼƬԤ������й���У����
3)����ͼƬ������ȱ�ݵ����⣬������ʱ�����²�����һ���������ڵ����������Ҫ����ʱע�⾵ͷǰ�޸����
Others:1)20ͼ��ⲻ���������±ߵ�������������Ϊԭͼ��ȱ�ݣ����¼�⵽��canny��Ե����Ͳ���ȱ�ڣ�������ⲻ����Ͳ��������
2)14��21��23��32��71ͼ��ⲻ���������Ǽ�⵽�ľ��β�߲����غϣ����»�������������ںϺ�õ�һ��������Ķ���Σ�
3)24��66ͼ��ⲻ�������ϲ�����������canny��Ե��ȡ����������ȱ�ڣ�
4)35ͼ��ⲻ�����Ŵ��±ߵ�����������canny��ȡ���ĸ������Ե��ȱ�ڣ�
5)54��58��59ͼ��ⲻ�����Ŵ��±ߵ���������������ʱ��һ�����ߵ�ס�ˣ�
6)61��63��64��67��68��69��73ͼ��ⲻ�������²�������Ϊ�������⵼��canny��ȡ�����²������Ե
************************************************************/

#include "cv.h"
#include "highgui.h"
#include <vector>
#include <windows.h>												//MessageBoxA����ͷ�ļ�
#include <string>
#include <iostream>
#define duty_cycle_threshold 0.7									//�������ʱ��ռ�ձ�(�����������С�������֮��)����ֵ��0.7���
#define duty_cycle_threshold_fuse 0.5								//�����ε�ռ�ձ���ֵ
#define contours_tatal_threshold 30									//�����е�Ԫ�أ��㣩����
#define ostu_coefficient 1.0										//ostu����õ���ֵ�ı���ϵ��
#define kernel_coefficient 1										//��̬ѧ�˵Ĳ��������ڱղ���
#define kernel_coefficient2 2										//��̬ѧ�˵Ĳ���,���ں���ʴ
#define kernel_coefficient3 2										//��̬ѧ�˵Ĳ��������ڶ�canny��Եͼ�������ͣ�֮ǰ�Ĳ�����1
#define expand_edge_coefficient 6									//�����������һ�������ľ��εı�Ե��Ŀ��ʹ���ŵĸ�����������һ��
#define aspect_ratio_min_expand 1									//�ɻ����ŵĳ������Сֵ
#define aspect_ratio_max_expand 2									//�ɻ����ŵĳ�������ֵ
#define aspect_ratio_min 1.2										//�ɻ����ŵĳ������Сֵ
#define aspect_ratio_max 3											//�ɻ����ŵĳ�������ֵ
#define contour_area_max 1000										//�ɻ����������ֵ
#define area_max 3000												//�ɻ����������ֵ
int nThresholdEdge = 100;											//canny�㷨��ֵ
int element_shape = CV_SHAPE_RECT;									//�˵���״Ϊ����
int angle_correcting;												//����У����ĽǶ�
int selective_picture = 66;											//���ڵ�������һ��ͼƬ
using namespace std;
int otsu(const IplImage* image, int x0, int y0, int dx, int dy);	//ostu������ֵ����

/*����ȫ�ֱ���*/
const char *pstrWindowsCannyTitle = "��Ե���ͼ";			//�������������ڴ��ڣ���canny��Ե���򣩵�����
IplImage* gray;												//ԭͼ�ĻҶ�ͼ
IplImage* canny_img;											//canny�㷨���ͼ����ֵ��ͼ

/*����canny�㷨������ֵͼ��canny_img�������*/
void on_trackbar(int threshold)
{
	//canny��Ե���  
	cvCanny(gray, canny_img, threshold, threshold * 3, 3);
	cvShowImage(pstrWindowsCannyTitle, canny_img);
}

struct ChipInfo
{
	CvBox2D box;													//OpenCV��2D���ӽṹ�������������ĺ������ꡢ�����ƫ�ƽǶ��������
	double area;													//������Χ���
	float min_rectangle_area;										//��С��Ӿ������
	float duty_cycle;												//ռ�ձȣ������������С��Ӿ���֮�ȣ�	
	float aspect_ratio;												//�����
};
int main()
{
	/*����canny�㷨����ʾ���ڼ�������ֵ�Ļ�����*/
	const char *pstrWindowsToolBar = "Threshold";				//����������������
	cvNamedWindow(pstrWindowsCannyTitle, CV_WINDOW_AUTOSIZE);	//������������									//������������ʼλ��
	cvCreateTrackbar(pstrWindowsToolBar, pstrWindowsCannyTitle, &nThresholdEdge, 255, on_trackbar);			//����������
	//on_trackbar(1);												//��ʼ��ӦֵΪnThresholdEdge

	/*����һϵ�е���ʾ����*/
	cvNamedWindow("Src", 1);										//CV_DEFAULT=0�����ڵĴ�С������ͼ��Ĵ�С���ı䣻CV_WINDOW_AUTOSIZE=1������������ͼ���ʵ�ʴ�С�Զ����������������������ͼ��
	cvNamedWindow("Contours_Detect", 1);
	cvNamedWindow("rectangle_detect_fuse", 1);
	cvNamedWindow("Rectangle_Detect_Fuse_Rect", 1);
	cvNamedWindow("Contours_Detect_Fuse", 1);
	cvNamedWindow("Rectangle_Detect_Final_Result", 1);
	cvNamedWindow("Dst_Detection", 1);
	cvNamedWindow("rectangle_detect", 1);
	cvNamedWindow("dst", 1);

	/*����Դͼ�񣬲���ʾ��Src������*/
	string s_input = "F:\\ͼƬ\\�ɻ�����ͼƬ\\snap1\\snap1\\snap00";
	string s1;
	string s_output = "F:\\ͼƬ\\�ɻ�����ͼƬ\\1_6_4_v1\\snap00";

	/*��������ͼƬ�����ͼƬ�ľ���·��*/
	const char *picstr_input;												//����ͼƬ�ľ���·��
	const char *picstr_output;												//���ͼƬ�ľ���·��						
	for (int picnum = 8; picnum <= 73; picnum++)
	{
		/*���ڵ��Ե�ʱ���ض����ĳһ��ͼƬ�ļ�����*/
		//if (picnum != selective_picture)
			//continue;

		if (picnum < 10)
		{
			s_input = s_input + '0';											//���ͼƬ���к�С��10������Ҫ�����к�ǰ�油��һ��0����
			s_output = s_output + '0';								//���ͼƬ���к�С��10������Ҫ�����к�ǰ�油��һ��0����
		}
		s1 = to_string(picnum);										//����Ҫ�����κ�ͷ�ļ���Ӧ������utility�У������������ֱ��ʹ�ã��������κ�������������תΪstring�����غ���
		s_input = s_input + s1 + ".jpg";										//����ͼƬ�ľ���·��
		s_output = s_output + s1 + ".jpg";										//����ͼƬ�ľ���·��
		picstr_input = s_input.c_str();								//��string����ת��ΪC����ַ���
		picstr_output = s_output.c_str();								//��string����ת��ΪC����ַ���
		IplImage* src = cvLoadImage(picstr_input, -1);					//#define CV_LOAD_IMAGE_UNCHANGED  -1 Ҳ���Ǳ���ͼƬ��ԭ״����
		src->origin = IPL_ORIGIN_TL;								//��ͼƬ��ԭ������λ���˹���λ
		cvShowImage("Src", src);										//��ʾͼ��

		/*����dst,rectangle_detect,gray*/
		IplImage* dst = cvCloneImage(src);											//dstΪ���ľ��μ����ͼ
		IplImage* dst_detection = cvCloneImage(src);											//dstΪ���ľ��μ����ͼ
		IplImage* rectangle_detect = cvCreateImage(cvGetSize(src), 8, 3);			//rectangle_detectΪɸѡ������Ͼ���ͼ
		cvZero(rectangle_detect);
		IplImage* rectangle_detect_fuse_rect = cvCreateImage(cvGetSize(src), 8, 3);			//rectangle_detectΪɸѡ������Ͼ���ͼ
		cvZero(rectangle_detect_fuse_rect);
		IplImage* rectangle_detect_final = cvCreateImage(cvGetSize(src), 8, 3);			//rectangle_detectΪ���յõ��ķɻ�������Ͼ���ͼ
		cvZero(rectangle_detect_final);
		IplImage* rectangle_detect_fuse = cvCreateImage(cvGetSize(src), 8, 1);			//rectangle_detect_fuseΪ�������϶�ֵͼ
		cvZero(rectangle_detect_fuse);
		IplImage* contours_detect = cvCreateImage(cvGetSize(src), 8, 3);			//contours_detectΪ��⵽����������ͼ
		IplImage* contours_detect_fuse = cvCreateImage(cvGetSize(src), 8, 3);			//contours_detect_fuseΪ����ľ��ε���Ӿ���ͼ
		gray = cvCreateImage(cvGetSize(src), 8, 1);						//depth=8 channels=1
		cvCvtColor(src, gray, CV_RGB2GRAY);											//��Դͼ��srcת���ɻҶ�ͼgray
		canny_img = cvCreateImage(cvGetSize(src), 8, 1);						//depth=8 channels=1
		IplImage * temp = cvCreateImage(cvGetSize(src), 8, 1);					//�������ղ����ǵ���ʱͼ�����ڱ���in-place����
		IplConvKernel* element = 0;												//������̬ѧ����ĺ�
		IplConvKernel* element2 = 0;											//������̬ѧ����ĺ�
		IplConvKernel* element3 = 0;											//������̬ѧ����ĺ�

		/*����canny�㷨������ֵͼ��canny_img�������*/
		cvCanny(gray, canny_img, nThresholdEdge, nThresholdEdge * 3, 3);
		element = cvCreateStructuringElementEx(kernel_coefficient * 2 + 1, kernel_coefficient * 2 + 1, kernel_coefficient, kernel_coefficient, element_shape, 0);
		cvMorphologyEx(canny_img, canny_img, temp, element, CV_MOP_CLOSE, 1);					//default 3*3�����бղ������㣬�������ܹ��ų�С�ͺڶ�����ɫ����
		element3 = cvCreateStructuringElementEx(kernel_coefficient3 * 2 + 1, kernel_coefficient3 * 2 + 1, kernel_coefficient3, kernel_coefficient3, element_shape, 0);
		cvDilate(canny_img, canny_img, element3, 1);
		cvShowImage(pstrWindowsCannyTitle, canny_img);

		///*������ֵͼ��gray_clone�������*/
		//iplimage* gray_clone = cvcloneimage(gray);																//�����Ҷ�ͼ��gray�ĸ���gray_clone
		//int threshold = otsu(gray_clone, 0, 0, gray_clone->width, gray_clone->height) * ostu_coefficient;		//��ostu����ostu_coefficient����Ϊ��ֵ��ͼ�����ֵ
		//cvthreshold(gray_clone, gray_clone, threshold, 255, cv_thresh_binary);									//gray_cloneΪostu����ֵ�ָ��Ķ�ֵͼ��
		//cvnamedwindow("gray_threshold_image", 1);
		//cvnamedwindow("contours_detect", 1);
		//cvshowimage("gray_threshold_image", gray_clone);
		//cvsaveimage("gray_threshold.jpg", gray_clone);

		///*��ʴ������ͼ��*/
		//cvErode(gray_clone, gray_clone);
		//cvDilate(gray_clone, gray_clone);

		/*�ҵ�ͼ���е���������*/
		CvMemStorage* storage = cvCreateMemStorage(0);

		CvSeq* contours;
		cvFindContours(canny_img, storage, &contours, sizeof(CvContour), CV_RETR_TREE,
			CV_CHAIN_APPROX_NONE, cvPoint(0, 0));						//�Ҷ�ֵͼ���е�������CV_RETR_TREE - ��ȡ���������������ع�Ƕ��������ȫ�� hierarchy��CV_CHAIN_APPROX_NONE - �����е���������ʽ����(ת����Ϊ��������ʽ 

		/*��Contours_Detect�����л�����⵽����������*/
		if (contours)
			cvDrawContours(contours_detect, contours, cvScalarAll(255), cvScalarAll(255), 100);				//��contours_detect�л������е�����
		cvShowImage("Contours_Detect", contours_detect);
		cvSaveImage("Contours_Detect.jpg", contours_detect);

		/*��ÿһ���������ɸѡ�����������ĺ�ѡ������������ѡ������ChipInfo�ṹ��ѹ�뵽������*/
		std::vector <ChipInfo> candiate_rect_vec0;						//����ChipInfo����������ΪChipInfo�ṹ
		std::vector <ChipInfo> candiate_rect_vec1;						//����ChipInfo����������ΪChipInfo�ṹ
		std::vector <ChipInfo> candiate_rect_vec2;						//����ChipInfo����������ΪChipInfo�ṹ
		std::vector <ChipInfo> candiate_rect_vec3;						//����ChipInfo����������ΪChipInfo�ṹ
		std::vector <ChipInfo> candiate_rect_vec_fuse;					//����ChipInfo����������ΪChipInfo�ṹ
		ChipInfo chip;

		/*���뵽�������������0�㣩���ж����Ƿ�����������*/
		for (; contours; contours = contours->h_next)
		{
			/*�жϸ��������ڵ�ĵ����Ƿ����ĳ����ֵ*/
			if (contours->total < contours_tatal_threshold)
			{
				continue;
			}

			/*ɸѡ��ռ�ձȴ���ĳ����ֵ������*/
			CvBox2D box_outer = cvMinAreaRect2(contours);			//����cvMinAreaRect2���Է���һ����Χ������С�ĳ����Σ��������������������б��
			double area = fabs(cvContourArea(contours));			//����cvContourArea���������򲿷�������������ڼ��㲿�����������ʱ�����������ߺ��������˵����Χ�ɵ����������������
			float min_rectangle_area = box_outer.size.width * box_outer.size.height;	//����������С��Ӿ��ε����
			float duty_cycle = area / min_rectangle_area;			//����ռ�ձȣ�Ϊ�������������С���������
			double angle_correcting_0 = fabs(box_outer.angle);
			double angle_correcting_90 = fabs(box_outer.angle - 90);							//У��������ת�Ƕȣ�ͳһ���εĳ����Ӧ��ʵ�ʳ���
			float aspect_ratio;
			bool angle_flag = angle_correcting_0 < angle_correcting_90;
			if (angle_flag)
				aspect_ratio = box_outer.size.width / box_outer.size.height;	//����������С��Ӿ��εĳ����
			else
				aspect_ratio = box_outer.size.height / box_outer.size.width;	//����������С��Ӿ��εĳ����
			if ((duty_cycle > duty_cycle_threshold) && (area > contour_area_max))
			{
				/*��һ��ChipInfo�ṹ���и�ֵ*/
				printf("test ��0���angleΪ%f,  widthΪ%f,  heightΪ%f,  aspect_ratioΪ%f, angle_flagΪ%d\n", box_outer.angle, box_outer.size.width, box_outer.size.height, aspect_ratio, angle_flag);
				ChipInfo chip;
				if (angle_flag == 0)
					box_outer.size.width += expand_edge_coefficient;
				else
					box_outer.size.height += expand_edge_coefficient;
				chip.box = box_outer;					//chip�����box��ԱΪ��������С��Ӿ���
				chip.area = area;						//chip�����area��ԱΪ���������
				chip.min_rectangle_area = min_rectangle_area;		//chip�����min_rectangle_area��ԱΪ������С��Ӿ������;						//chip�����area��ԱΪ���������
				chip.duty_cycle = duty_cycle;			//chip�����duty_cycle��ԱΪ��������С��Ӿ��ε�ռ�ձ�
				candiate_rect_vec0.push_back(chip);		//��ÿ�����ɵ�ChipInfo����ѹ��ChipInfo����֮��
			}

			/*���ж����Ƿ������һ��������������������ͽ������ͬһ�����������*/
			if (!contours->v_next)
			{
				continue;
			}

			/*���뵽��һ����������һ�㣩*/
			CvSeq* contour_first = contours->v_next;
			for (; contour_first; contour_first = contour_first->h_next)
			{
				/*�жϸ��������ڵ�ĵ����Ƿ����ĳ����ֵ�����ж����Ƿ�����������*/
				if (contour_first->total < contours_tatal_threshold)
				{
					continue;
				}

				/*ɸѡ��ռ�ձȴ���ĳ����ֵ������*/
				CvBox2D box_outer = cvMinAreaRect2(contour_first);		//����cvMinAreaRect2���Է���һ����Χ������С�ĳ����Σ��������������������б��
				double area = fabs(cvContourArea(contour_first));		//����cvContourArea���������򲿷�������������ڼ��㲿�����������ʱ�����������ߺ��������˵����Χ�ɵ����������������
				float min_rectangle_area = box_outer.size.width * box_outer.size.height;	//����������С��Ӿ��ε����
				float duty_cycle = area / min_rectangle_area;			//����ռ�ձȣ�Ϊ�������������С���������
				double angle_correcting_0 = fabs(box_outer.angle);
				double angle_correcting_90 = fabs(box_outer.angle - 90);							//У��������ת�Ƕȣ�ͳһ���εĳ����Ӧ��ʵ�ʳ���
				float aspect_ratio;
				bool angle_flag = angle_correcting_0 < angle_correcting_90;
				if (angle_flag)
					aspect_ratio = box_outer.size.width / box_outer.size.height;	//����������С��Ӿ��εĳ����
				else
					aspect_ratio = box_outer.size.height / box_outer.size.width;	//����������С��Ӿ��εĳ����
				if ((duty_cycle > duty_cycle_threshold) && (area > contour_area_max))
				{
					/*��һ��ChipInfo�ṹ���и�ֵ*/
					printf("test ��1���angleΪ%f,  widthΪ%f,  heightΪ%f,  aspect_ratioΪ%f, angle_flagΪ%d\n", box_outer.angle, box_outer.size.width, box_outer.size.height, aspect_ratio, angle_flag);
					ChipInfo chip;
					if (angle_flag)
						box_outer.size.width += expand_edge_coefficient;
					else
						box_outer.size.height += expand_edge_coefficient;
					chip.box = box_outer;					//chip�����box��ԱΪ��������С��Ӿ���
					chip.area = area;						//chip�����area��ԱΪ���������
					chip.min_rectangle_area = min_rectangle_area;		//chip�����min_rectangle_area��ԱΪ������С��Ӿ������;						//chip�����area��ԱΪ���������
					chip.duty_cycle = duty_cycle;			//chip�����duty_cycle��ԱΪ��������С��Ӿ��ε�ռ�ձ�
					candiate_rect_vec1.push_back(chip);		//��ÿ�����ɵ�ChipInfo����ѹ��ChipInfo����֮��
				}

				/*���ж����Ƿ������һ��������������������ͽ������ͬһ�����������*/
				if (!(contour_first->v_next))
				{
					continue;
				}

				/*������һ���������ڶ��㣩*/
				CvSeq* contour_second = contour_first->v_next;
				for (; contour_second; contour_second = contour_second->h_next)
				{
					/*�жϸ��������ڵ�ĵ����Ƿ����ĳ����ֵ�����ж����Ƿ�����������*/
					if (contour_second->total < contours_tatal_threshold)
					{
						continue;
					}

					/*ɸѡ��ռ�ձȴ���ĳ����ֵ������*/
					CvBox2D box_outer = cvMinAreaRect2(contour_second);		//����cvMinAreaRect2���Է���һ����Χ������С�ĳ����Σ��������������������б��
					double area = fabs(cvContourArea(contour_second));		//����cvContourArea���������򲿷�������������ڼ��㲿�����������ʱ�����������ߺ��������˵����Χ�ɵ����������������
					float min_rectangle_area = box_outer.size.width * box_outer.size.height;	//����������С��Ӿ��ε����
					float duty_cycle = area / min_rectangle_area;			//����ռ�ձȣ�Ϊ�������������С���������
					double angle_correcting_0 = fabs(box_outer.angle);
					double angle_correcting_90 = fabs(box_outer.angle - 90);							//У��������ת�Ƕȣ�ͳһ���εĳ����Ӧ��ʵ�ʳ���
					float aspect_ratio;
					bool angle_flag = angle_correcting_0 < angle_correcting_90;
					if (angle_flag)
						aspect_ratio = box_outer.size.width / box_outer.size.height;	//����������С��Ӿ��εĳ����
					else
						aspect_ratio = box_outer.size.height / box_outer.size.width;	//����������С��Ӿ��εĳ����
					if (duty_cycle > duty_cycle_threshold)
					{
						/*��һ��ChipInfo�ṹ���и�ֵ*/
						ChipInfo chip;
						if (angle_flag == 0)
							box_outer.size.width += expand_edge_coefficient;
						else
							box_outer.size.height += expand_edge_coefficient;
						chip.box = box_outer;					//chip�����box��ԱΪ��������С��Ӿ���
						chip.area = area;						//chip�����area��ԱΪ���������
						chip.min_rectangle_area = min_rectangle_area;		//chip�����min_rectangle_area��ԱΪ������С��Ӿ������;						//chip�����area��ԱΪ���������
						chip.duty_cycle = duty_cycle;			//chip�����duty_cycle��ԱΪ��������С��Ӿ��ε�ռ�ձ�
						candiate_rect_vec2.push_back(chip);		//��ÿ�����ɵ�chip����ѹ��ChipInfo����֮��
					}

					/*���ж����Ƿ������һ��������������������ͽ������ͬһ�����������*/
					if (!(contour_second->v_next))
					{
						continue;
					}

					/*������һ�������������㣩*/
					CvSeq* contour_third = contour_second->v_next;
					for (; contour_third; contour_third = contour_third->h_next)
					{
						/*�жϸ��������ڵ�ĵ����Ƿ����ĳ����ֵ�����ж����Ƿ�����������*/
						if (contour_third->total < contours_tatal_threshold)
						{
							continue;
						}

						/*ɸѡ��ռ�ձȴ���ĳ����ֵ������*/
						CvBox2D box_outer = cvMinAreaRect2(contour_third);		//����cvMinAreaRect2���Է���һ����Χ������С�ĳ����Σ��������������������б��
						double area = fabs(cvContourArea(contour_third));		//����cvContourArea���������򲿷�������������ڼ��㲿�����������ʱ�����������ߺ��������˵����Χ�ɵ����������������
						float min_rectangle_area = box_outer.size.width * box_outer.size.height;	//����������С��Ӿ��ε����
						float duty_cycle = area / min_rectangle_area;			//����ռ�ձȣ�Ϊ�������������С���������
						double angle_correcting_0 = fabs(box_outer.angle);
						double angle_correcting_90 = fabs(box_outer.angle - 90);							//У��������ת�Ƕȣ�ͳһ���εĳ����Ӧ��ʵ�ʳ���
						float aspect_ratio;
						bool angle_flag = angle_correcting_0 < angle_correcting_90;
						if (angle_flag)
							aspect_ratio = box_outer.size.width / box_outer.size.height;	//����������С��Ӿ��εĳ����
						else
							aspect_ratio = box_outer.size.height / box_outer.size.width;	//����������С��Ӿ��εĳ����
						if (duty_cycle > duty_cycle_threshold)
						{
							/*��һ��ChipInfo�ṹ���и�ֵ*/
							ChipInfo chip;
							if (angle_flag == 0)
								box_outer.size.width += expand_edge_coefficient;
							else
								box_outer.size.height += expand_edge_coefficient;
							chip.box = box_outer;					//chip�����box��ԱΪ��������С��Ӿ���
							chip.area = area;						//chip�����area��ԱΪ���������
							chip.min_rectangle_area = min_rectangle_area;		//chip�����min_rectangle_area��ԱΪ������С��Ӿ������;						//chip�����area��ԱΪ���������
							chip.duty_cycle = duty_cycle;			//chip�����duty_cycle��ԱΪ��������С��Ӿ��ε�ռ�ձ�
							candiate_rect_vec3.push_back(chip);		//��ÿ�����ɵ�chip����ѹ��ChipInfo����֮��
						}
					}
				}
			}
		}

		/*�õ��˵�0��һЩ��ѡ��������趨ռ�ձ�/����Ⱦ���ӽ�1�ĺ�ѡĿ��ΪĿ��*/
		float likely_max0 = -1;
		int index0 = -1;
		for (int t = candiate_rect_vec0.size() - 1; t >= 0; t--)
		{
			if (likely_max0 < candiate_rect_vec0[t].duty_cycle)
			{
				likely_max0 = candiate_rect_vec0[t].duty_cycle;
				index0 = t;														//�����±��0��ʼ
			}
		}

		/*�����0����ڷ���ɸѡ�����ĺ�ѡ��������ѡ��ռ�ձ������������л�ͼ���ú�ɫ��ʾ*/
		if (index0 >= 0)
		{
			CvPoint2D32f pt[4];
			for (int t = candiate_rect_vec0.size() - 1; t >= 0; t--)
			{
				cvBoxPoints(candiate_rect_vec0[t].box, pt);						//�ҵ����ο򶥵������
				CvPoint pt0, pt1;
				pt0 = cvPoint(cvRound(pt[0].x), cvRound(pt[0].y));
				pt1 = cvPoint(cvRound(pt[2].x), cvRound(pt[2].y));
				cvRectangle(dst, pt0, pt1, cvScalar(0, 0, 255), 1, 4, 0);
				cvRectangle(rectangle_detect, pt0, pt1, cvScalar(0, 0, 255), 1, 4, 0);										//��ɸѡ����������ľ���
				cvRectangle(rectangle_detect_fuse, pt0, pt1, cvScalar(255), CV_FILLED, 4, 0);								//������ľ���
				printf("0 level %d contours area is %lf.\t", t, candiate_rect_vec0[t].area);								//����Ļ��������������
				printf("0 level %d min_rectangle_area is %f.\t", t, candiate_rect_vec0[t].min_rectangle_area);			    //����Ļ�����������С��Ӿ��ε����
				printf("0 level %d duty_cycle is %f.\n", t, candiate_rect_vec0[t].duty_cycle);								//����Ļ�����������ռ�ձ�
			}

			cvLine(dst, cvPoint(cvRound(candiate_rect_vec0[index0].box.center.x - 5),
				cvRound(candiate_rect_vec0[index0].box.center.y)),
				cvPoint(cvRound(candiate_rect_vec0[index0].box.center.x + 5),
				cvRound(candiate_rect_vec0[index0].box.center.y)),
				CV_RGB(255, 0, 0), 1);
			cvLine(dst, cvPoint(cvRound(candiate_rect_vec0[index0].box.center.x),
				cvRound(candiate_rect_vec0[index0].box.center.y - 5)),
				cvPoint(cvRound(candiate_rect_vec0[index0].box.center.x),
				cvRound(candiate_rect_vec0[index0].box.center.y + 5)),
				CV_RGB(255, 0, 0), 1);
			char a[100];
			sprintf(a, "chip0 pos:(%d , %d),angle: %d", cvRound(candiate_rect_vec0[index0].box.center.x),
				cvRound(candiate_rect_vec0[index0].box.center.y),
				cvRound(candiate_rect_vec0[index0].box.angle));
			//MessageBoxA(NULL, a, "chip0 information", MB_OK);
		}
		else
		{
			char a[100];
			sprintf(a, "No Chip0");
			//MessageBoxA(NULL, a, "chip information", MB_OK);
		}

		/*�õ��˵�1��һЩ��ѡ��������趨ռ�ձ�/����Ⱦ���ӽ�1�ĺ�ѡĿ��ΪĿ�꣬����ɫ��ʾ*/
		float likely_max1 = -1;
		int index1 = -1;
		for (int t = candiate_rect_vec1.size() - 1; t >= 0; t--)
		{
			if (likely_max1 < candiate_rect_vec1[t].duty_cycle)
			{
				likely_max1 = candiate_rect_vec1[t].duty_cycle;
				index1 = t;														//�����±��0��ʼ
			}
		}

		/*�����1����ڷ���ɸѡ�����ĺ�ѡ��������ѡ��ռ�ձ������������л�ͼ*/
		if (index1 >= 0)
		{
			CvPoint2D32f pt[4];
			for (int t = candiate_rect_vec1.size() - 1; t >= 0; t--)
			{
				cvBoxPoints(candiate_rect_vec1[t].box, pt);						//�ҵ����ο򶥵������
				CvPoint pt0, pt1;
				pt0 = cvPoint(cvRound(pt[0].x), cvRound(pt[0].y));
				pt1 = cvPoint(cvRound(pt[2].x), cvRound(pt[2].y));
				cvRectangle(dst, pt0, pt1, cvScalar(0, 255, 0), 1, 4, 0);
				cvRectangle(rectangle_detect, pt0, pt1, cvScalar(0, 255, 0), 1, 4, 0);										//��ɸѡ����������ľ���
				cvRectangle(rectangle_detect_fuse, pt0, pt1, cvScalar(255), CV_FILLED, 4, 0);								//������ľ���
				printf("1 level %d contours area is %lf.\t", t, candiate_rect_vec1[t].area);								//����Ļ��������������
				printf("1 level %d min_rectangle_area is %f.\t", t, candiate_rect_vec1[t].min_rectangle_area);			    //����Ļ�����������С��Ӿ��ε����
				printf("1 level %d duty_cycle is %f.\n", t, candiate_rect_vec1[t].duty_cycle);								//����Ļ�����������ռ�ձ�
			}

			cvLine(dst, cvPoint(cvRound(candiate_rect_vec1[index1].box.center.x - 5),
				cvRound(candiate_rect_vec1[index1].box.center.y)),
				cvPoint(cvRound(candiate_rect_vec1[index1].box.center.x + 5),
				cvRound(candiate_rect_vec1[index1].box.center.y)),
				CV_RGB(255, 0, 0), 1);
			cvLine(dst, cvPoint(cvRound(candiate_rect_vec1[index1].box.center.x),
				cvRound(candiate_rect_vec1[index1].box.center.y - 5)),
				cvPoint(cvRound(candiate_rect_vec1[index1].box.center.x),
				cvRound(candiate_rect_vec1[index1].box.center.y + 5)),
				CV_RGB(255, 0, 0), 1);
			char a[100];
			sprintf(a, "chip1 pos:(%d , %d),angle: %d", cvRound(candiate_rect_vec1[index1].box.center.x),
				cvRound(candiate_rect_vec1[index1].box.center.y),
				cvRound(candiate_rect_vec1[index1].box.angle));
			//MessageBoxA(NULL, a, "chip1 information", MB_OK);
		}
		else
		{
			char a[100];
			sprintf(a, "No Chip1");
			//MessageBoxA(NULL, a, "chip information", MB_OK);
		}

		/*�õ��˵�2��һЩ��ѡ��������趨ռ�ձ�/����Ⱦ���ӽ�1�ĺ�ѡĿ��ΪĿ�꣬����ɫ��ʾ*/
		float likely_max2 = -1;
		int index2 = -1;
		for (int t = candiate_rect_vec2.size() - 1; t >= 0; t--)
		{
			if (likely_max2 < candiate_rect_vec2[t].duty_cycle)
			{
				likely_max2 = candiate_rect_vec2[t].duty_cycle;
				index2 = t;														//�����±��0��ʼ
			}
		}

		/*�����2����ڷ���ɸѡ�����ĺ�ѡ��������ѡ��ռ�ձ������������л�ͼ*/
		if (index2 >= 0)
		{
			CvPoint2D32f pt[4];
			for (int t = candiate_rect_vec2.size() - 1; t >= 0; t--)
			{
				cvBoxPoints(candiate_rect_vec2[t].box, pt);						//�ҵ����ο򶥵������
				CvPoint pt0, pt1;
				pt0 = cvPoint(cvRound(pt[0].x), cvRound(pt[0].y));
				pt1 = cvPoint(cvRound(pt[2].x), cvRound(pt[2].y));
				cvRectangle(dst, pt0, pt1, cvScalar(255, 0, 0), 1, 4, 0);
				cvRectangle(rectangle_detect, pt0, pt1, cvScalar(255, 0, 0), 1, 4, 0);										//��ɸѡ����������ľ���
				cvRectangle(rectangle_detect_fuse, pt0, pt1, cvScalar(255), CV_FILLED, 4, 0);								//������ľ���
				printf("2 level %d contours area is %lf.\t", t, candiate_rect_vec2[t].area);								//����Ļ��������������
				printf("2 level %d min_rectangle_area is %f.\n", t, candiate_rect_vec2[t].min_rectangle_area);			    //����Ļ�����������С��Ӿ��ε����
				printf("2 level %d duty_cycle is %f.\n", t, candiate_rect_vec2[t].duty_cycle);								//����Ļ�����������ռ�ձ�
			}

			cvLine(dst, cvPoint(cvRound(candiate_rect_vec2[index2].box.center.x - 5),
				cvRound(candiate_rect_vec2[index2].box.center.y)),
				cvPoint(cvRound(candiate_rect_vec2[index2].box.center.x + 5),
				cvRound(candiate_rect_vec2[index2].box.center.y)),
				CV_RGB(255, 0, 0), 1);
			cvLine(dst, cvPoint(cvRound(candiate_rect_vec2[index2].box.center.x),
				cvRound(candiate_rect_vec2[index2].box.center.y - 5)),
				cvPoint(cvRound(candiate_rect_vec2[index2].box.center.x),
				cvRound(candiate_rect_vec2[index2].box.center.y + 5)),
				CV_RGB(255, 0, 0), 1);
			char a[100];
			sprintf(a, "chip2 pos:(%d , %d),angle: %d", cvRound(candiate_rect_vec2[index2].box.center.x),
				cvRound(candiate_rect_vec2[index2].box.center.y),
				cvRound(candiate_rect_vec2[index2].box.angle));
			//MessageBoxA(NULL, a, "chip2 information", MB_OK);
		}
		else
		{
			char a[100];
			sprintf(a, "No Chip2");
			//MessageBoxA(NULL, a, "chip information", MB_OK);
		}

		/*�õ��˵�3��һЩ��ѡ��������趨ռ�ձ�/����Ⱦ���ӽ�1�ĺ�ѡĿ��ΪĿ��*/
		float likely_max3 = -1;
		int index3 = -1;
		for (int t = candiate_rect_vec3.size() - 1; t >= 0; t--)
		{
			if (likely_max3 < candiate_rect_vec3[t].duty_cycle)
			{
				likely_max3 = candiate_rect_vec3[t].duty_cycle;
				index3 = t;														//�����±��0��ʼ
			}
		}

		/*�����3����ڷ���ɸѡ�����ĺ�ѡ��������ѡ��ռ�ձ������������л�ͼ���û�ɫ��ʾ*/
		if (index3 >= 0)
		{
			CvPoint2D32f pt[4];
			for (int t = candiate_rect_vec3.size() - 1; t >= 0; t--)
			{
				cvBoxPoints(candiate_rect_vec3[t].box, pt);						//�ҵ����ο򶥵������
				CvPoint pt0, pt1;
				pt0 = cvPoint(cvRound(pt[0].x), cvRound(pt[0].y));
				pt1 = cvPoint(cvRound(pt[2].x), cvRound(pt[2].y));
				cvRectangle(dst, pt0, pt1, cvScalar(255, 255, 0), 1, 4, 0);
				cvRectangle(rectangle_detect, pt0, pt1, cvScalar(255, 255, 0), 1, 4, 0);										//��ɸѡ����������ľ���
				cvRectangle(rectangle_detect_fuse, pt0, pt1, cvScalar(255), CV_FILLED, 4, 0);								//������ľ���
				printf("3 level %d contours area is %lf.\t", t, candiate_rect_vec3[t].area);								//����Ļ��������������
				printf("3 level %d min_rectangle_area is %f.\n", t, candiate_rect_vec3[t].min_rectangle_area);			    //����Ļ�����������С��Ӿ��ε����
				printf("3 level %d duty_cycle is %f.\n", t, candiate_rect_vec3[t].duty_cycle);								//����Ļ�����������ռ�ձ�
			}

			cvLine(dst, cvPoint(cvRound(candiate_rect_vec3[index3].box.center.x - 5),
				cvRound(candiate_rect_vec3[index3].box.center.y)),
				cvPoint(cvRound(candiate_rect_vec3[index3].box.center.x + 5),
				cvRound(candiate_rect_vec3[index3].box.center.y)),
				CV_RGB(255, 0, 0), 1);
			cvLine(dst, cvPoint(cvRound(candiate_rect_vec3[index3].box.center.x),
				cvRound(candiate_rect_vec3[index3].box.center.y - 5)),
				cvPoint(cvRound(candiate_rect_vec3[index3].box.center.x),
				cvRound(candiate_rect_vec3[index3].box.center.y + 5)),
				CV_RGB(255, 0, 0), 1);
			char a[100];
			sprintf(a, "chip3 pos:(%d , %d),angle: %d", cvRound(candiate_rect_vec3[index3].box.center.x),
				cvRound(candiate_rect_vec3[index3].box.center.y),
				cvRound(candiate_rect_vec3[index3].box.angle));
			//MessageBoxA(NULL, a, "chip3 information", MB_OK);
		}
		else
		{
			char a[100];
			sprintf(a, "No Chip3");
			//MessageBoxA(NULL, a, "chip information", MB_OK);
		}

		/*�������ľ���*/
		element2 = cvCreateStructuringElementEx(kernel_coefficient2 * 2 + 1, kernel_coefficient2 * 2 + 1, kernel_coefficient2, kernel_coefficient2, element_shape, 0);
		cvErode(rectangle_detect_fuse, rectangle_detect_fuse, element2, 1);					//default 3*3�����бղ������㣬�������ܹ��ų�С�ͺڶ�����ɫ����
		cvShowImage("rectangle_detect_fuse", rectangle_detect_fuse);

		/*rectangle_detect�����ں�*/
		if ((index0 >= 0) || (index1 >= 0) || (index2 >= 0) || (index3 >= 0))
		{
			//cvThreshold(rectangle_detect, rectangle_detect, 128, 255, CV_THRESH_BINARY);				//��������ɫ�Ŀ�ת��Ϊ��ɫ��
			CvMemStorage* storage_fuse = cvCreateMemStorage(0);
			CvSeq* contours_fuse;
			cvFindContours(rectangle_detect_fuse, storage_fuse, &contours_fuse, sizeof(CvContour), CV_RETR_TREE,
				CV_CHAIN_APPROX_NONE, cvPoint(0, 0));						//�Ҷ�ֵͼ���е�������CV_RETR_TREE - ��ȡ���������������ع�Ƕ��������ȫ�� hierarchy��CV_CHAIN_APPROX_NONE - �����е���������ʽ����(ת����Ϊ��������ʽ 

			/*��Contours_Detect_Fuse�����л�����⵽����������*/
			if (contours_fuse)
				cvDrawContours(contours_detect_fuse, contours_fuse, cvScalarAll(255), cvScalarAll(255), 100);				//��contours_detect�л������е�����
			cvShowImage("Contours_Detect_Fuse", contours_detect_fuse);

			for (; contours_fuse; contours_fuse = contours_fuse->h_next)
			{
				CvBox2D box_outer = cvMinAreaRect2(contours_fuse);			//����cvMinAreaRect2���Է���һ����Χ������С�ĳ����Σ��������������������б��
				double area = fabs(cvContourArea(contours_fuse));			//����cvContourArea���������򲿷�������������ڼ��㲿�����������ʱ�����������ߺ��������˵����Χ�ɵ����������������
				angle_correcting = box_outer.angle;							//У��������ת�Ƕȣ�ͳһ���εĳ����Ӧ��ʵ�ʳ���
				float aspect_ratio;
				if (angle_correcting < 45)
					aspect_ratio = box_outer.size.width / box_outer.size.height;	//����������С��Ӿ��εĳ����
				else
					aspect_ratio = box_outer.size.height / box_outer.size.width;	//����������С��Ӿ��εĳ����
				float min_rectangle_area = box_outer.size.width * box_outer.size.height;	//����������С��Ӿ��ε����
				float duty_cycle = area / min_rectangle_area;			//����ռ�ձȣ�Ϊ�������������С���������
				printf("angle %f width %f height %f.\n", box_outer.angle, box_outer.size.width, box_outer.size.height);
				printf("candidate rectangle fuse aspect_ratio is %f.\n", aspect_ratio);			    //����Ļ����������������С��Ӿ��εĳ���ȣ��Ա���ȷ���������С�������ֵ

				CvPoint2D32f pt[4];												//������Ӿ��ε�4������
				cvBoxPoints(box_outer, pt);						//�ҵ����ο򶥵������
				CvPoint pt0, pt1;
				pt0 = cvPoint(cvRound(pt[0].x), cvRound(pt[0].y));
				pt1 = cvPoint(cvRound(pt[2].x), cvRound(pt[2].y));
				cvRectangle(rectangle_detect_fuse_rect, pt0, pt1, cvScalar(0, 255, 255), 1, 4, 0);										//��ɸѡ����������ľ���		
				cvShowImage("Rectangle_Detect_Fuse_Rect", rectangle_detect_fuse_rect);

				if ((duty_cycle >= duty_cycle_threshold_fuse) && (aspect_ratio >= aspect_ratio_min) && (aspect_ratio <= aspect_ratio_max) && (area >= area_max))				//ɸѡ��ռ�ձȣ�����Ⱥ��������һ����������Ӿ���
				{
					/*��һ��ChipInfo�ṹ���и�ֵ*/
					chip.box = box_outer;					//chip�����box��ԱΪ��������С��Ӿ���
					chip.area = area;						//chip�����area��ԱΪ���������
					chip.min_rectangle_area = min_rectangle_area;		//chip�����min_rectangle_area��ԱΪ������С��Ӿ������;						//chip�����area��ԱΪ���������
					chip.duty_cycle = duty_cycle;			//chip�����duty_cycle��ԱΪ��������С��Ӿ��ε�ռ�ձ�
					chip.aspect_ratio = aspect_ratio;			//chip�����aspect_ratio��ԱΪ��С��Ӿ��εĳ����
					candiate_rect_vec_fuse.push_back(chip);		//��ÿ�����ɵ�ChipInfo����ѹ��ChipInfo����֮��
				}
			}

			//CvPoint2D32f pt[4];
			for (int t = candiate_rect_vec_fuse.size() - 1; t >= 0; t--)
			{
				CvPoint2D32f pt[4];													//������Ӿ��ε�4������
				cvBoxPoints(candiate_rect_vec_fuse[t].box, pt);						//�ҵ����ο򶥵������
				CvPoint pt0, pt1;
				pt0 = cvPoint(cvRound(pt[0].x), cvRound(pt[0].y));
				pt1 = cvPoint(cvRound(pt[2].x), cvRound(pt[2].y));
				cvRectangle(dst, pt0, pt1, cvScalar(0, 0, 255), 2, 4, 0);
				cvRectangle(dst_detection, pt0, pt1, cvScalar(0, 0, 255), 2, 4, 0);
				cvRectangle(rectangle_detect_final, pt0, pt1, cvScalar(0, 0, 255), 2, 4, 0);										//��ɸѡ����������ľ���
				printf("fuse %d contours area is %lf.\t", t, candiate_rect_vec_fuse[t].area);								//����Ļ��������������
				printf("fuse %d min_rectangle_area is %f.\n", t, candiate_rect_vec_fuse[t].min_rectangle_area);			    //����Ļ�����������С��Ӿ��ε����
				printf("fuse %d duty_cycle is %f.\n", t, candiate_rect_vec_fuse[t].duty_cycle);								//����Ļ�����������ռ�ձ�
				printf("fuse %d aspect_ratio is %f.\n", t, candiate_rect_vec_fuse[t].aspect_ratio);			    //����Ļ�����������С��Ӿ��εĳ����
			}

			cvShowImage("Rectangle_Detect_Final_Result", rectangle_detect_final);
			cvShowImage("Dst_Detection", dst_detection);
			cvSaveImage(picstr_output, dst_detection);						//������յĽ��
		}

		/*��ʾ���*/
		if ((index0 >= 0) || (index1 >= 0) || (index2 >= 0) || (index3 >= 0))
		{
			cvShowImage("rectangle_detect", rectangle_detect);
			cvSaveImage("rectangle_detect.jpg", rectangle_detect);
			cvShowImage("dst", dst);
			cvSaveImage("dst.jpg", dst);
		}

		s_input = "F:\\ͼƬ\\�ɻ�����ͼƬ\\snap1\\snap1\\snap00";					//������һ��ͼƬ�����֣�ѭ����ȡ��һ��ͼƬ
		s_output = "F:\\ͼƬ\\�ɻ�����ͼƬ\\1_6_4_v1\\snap00";				//������һ��ͼƬ�����֣�ѭ�������һ��ͼƬ
		s1 = "";
	}

	cvWaitKey(0);
	return 0;
}

int otsu(const IplImage* image, int x0, int y0, int dx, int dy)
{

	unsigned char *np;      // ͼ��ָ��
	int thresholdValue = 1; // ��ֵ
	int ihist[256];             // ͼ��ֱ��ͼ��256����

	int i, j, k;          // various counters
	int n, n1, n2, gmin, gmax;
	double m1, m2, sum, csum, fmax, sb;

	// ��ֱ��ͼ����...
	memset(ihist, 0, sizeof(ihist));

	gmin = 255; gmax = 0;
	// ����ֱ��ͼ
	for (i = y0 + 1; i < y0 + dy - 1; i++)
	{
		np = (uchar*)(image->imageData + i*image->widthStep);
		// np = &image[i*cols+x0+1];
		for (j = x0 + 1; j < x0 + dx - 1; j++)
		{
			ihist[*np]++;
			if (*np > gmax) gmax = *np;
			if (*np < gmin) gmin = *np;
			np++; /* next pixel */
		}
	}

	// set up everything
	sum = csum = 0.0;
	n = 0;

	for (k = 0; k <= 255; k++) {
		sum += (double)k * (double)ihist[k];    /* x*f(x) ������*/
		n += ihist[k];                                         /*  f(x)    ����    */
	}

	if (!n)
	{
		// if n has no value, there is problems...
		return -1;
	}

	// do the otsu global thresholding method
	fmax = -1.0;
	n1 = 0;
	for (k = 0; k < 255; k++) {
		n1 += ihist[k];
		if (!n1) { continue; }
		n2 = n - n1;
		if (n2 == 0) { break; }
		csum += (double)k *ihist[k];
		m1 = csum / n1;
		m2 = (sum - csum) / n2;
		sb = (double)n1 *(double)n2 *(m1 - m2) * (m1 - m2);
		/* bbg: note: can be optimized. */
		if (sb > fmax) {
			fmax = sb;
			thresholdValue = k;
		}
	}

	// at this point we have our thresholding value

	// debug code to display thresholding values
	//cvWaitKey(0);
	return(thresholdValue);
}