
// SDLVideoDlg.h: 头文件
//

#pragma once

#define MAX_FRIENDLY_NAME_LENGTH    128  
#define MAX_MONIKER_NAME_LENGTH     256
#define MAX_PARAM_COUNT  8


// CSDLVideoDlg 对话框
class CSDLVideoDlg : public CDialog
{
// 构造
public:
	CSDLVideoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SDLVIDEO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	void show_dshow_device();
	int play();

public:
	AVFormatContext *m_pFormatCtx;
	AVInputFormat* m_ifmt;
	int m_videoindex;
	AVCodecContext  *m_pCodecCtx;
	AVCodec         *m_pCodec;

	SDL_Window* m_screen;
	SDL_Thread *decode_video_tid;
	SDL_Thread *fresh_video_tid;
	int thread_exit;
	int exit_push_thread;

	SDL_Thread *push_local_av_tid;

	SDL_Thread *show_friend_video_tid;
	SDL_Window* m_friend_screen;
	int exit_pull_thread;
	char* push_rtmp_url;
	char* pull_rtmp_url;

	

// 实现
protected:
	HICON m_hIcon;




	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
