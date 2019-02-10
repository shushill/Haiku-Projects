#include "MainWindow.h"


#include <Button.h>

#include <View.h>


#include <String.h>

/
enum
{
	M_BUTTON_CLICKED = 'btcl'
};


MainWindow::MainWindow(void)
	:	BWindow(BRect(100,100,300,200),"ClickMe",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS | 
																	B_QUIT_ON_WINDOW_CLOSE),
		fCount(0)
{
	BButton *button = new BButton(BRect(10,10,11,11),"button","Click Me!",
									new BMessage(M_BUTTON_CLICKED));
	
	button->ResizeToPreferred();
	
	
	AddChild(button);
}


void
MainWindow::MessageReceived(BMessage *msg)
{
	
	switch (msg->what)
	{
		case M_BUTTON_CLICKED:
		{
			fCount++;
			
			BString labelString("Clicks: ");
			
			labelString << fCount;
			
			
			SetTitle(labelString.String());
			break;
		}
		default:
		{
			
			BWindow::MessageReceived(msg);
			break;
		}
	}
}
