#include <QCursor>
#include <stdio.h>
#include "my_flag.h"
#include "ui_my_flag.h"


static Qt::WindowFlags popupWindowFlags =

#ifdef Q_WS_WIN
Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint
#else
Qt::Popup
#endif
;

my_flag::my_flag(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::my_flag)
{
    ui.setupUi(this);

    setWindowFlags( popupWindowFlags );

    connect( ui.pushButton, SIGNAL( clicked( bool ) ),
		this, SLOT( pushButtonClicked() ) );

    display = QX11Info::display();
}

my_flag::~my_flag()
{
    //delete ui;
}

void my_flag::pushButtonClicked()
{
  static int x = 0;

  x = x + 10;

  printf("x=%d\n", x);
  move( x, x );

  printf("Button pressed %s\n", isButtonPressed() ? "ture" : "false");
  //hideWindow();
}

void my_flag::hideWindow()
{
  hide();
}

bool my_flag::isButtonPressed() {
  XDeviceInfo *devices;
  XDevice     *device;
  XDeviceState *state;
  int num_devices;

  devices = XListInputDevices(display, &num_devices);
  //printf("num_devices = %d\n", num_devices);
  for (int loop = 0; loop < num_devices; loop++) {
	  //printf("device name: %s\n", devices[loop].name);
	  //printf("device use: %d\n", devices[loop].use);
	  device = XOpenDevice(display, devices[loop].id);
	  if(!device) 
		  continue;
	  
	  state = XQueryDeviceState(display, device);
	  if (!state)
		  continue;

	  if (isPressed(state))
		  return true;

	  XFreeDeviceState(state);
  }
  return false;
}

bool isPressed(XDeviceState *state) {
    int			loop;
    int			loop2;
    XInputClass		*cls;
    //XValuatorState	*val_state;
    //XKeyState		*key_state;
    XButtonState	*but_state;

        cls = state->data;
	//printf("%d class%s :\n", state->num_classes,
	       //(state->num_classes > 1) ? "es" : "");
	for(loop=0; loop<state->num_classes; loop++) {
	  switch(cls->c_class) {
	  case ValuatorClass:
	    //val_state = (XValuatorState *) cls;
	    //printf("ValuatorClass Mode=%s Proximity=%s\n",
		   //val_state->mode & 1 ? "Absolute" : "Relative",
		   //val_state->mode & 2 ? "Out" : "In");
	    //for(loop2=0; loop2<val_state->num_valuators; loop2++) {
	      //printf("\tvaluator[%d]=%d\n", loop2, val_state->valuators[loop2]);
	    //}
	    break;

	  case ButtonClass:
	    but_state = (XButtonState *) cls;
	    //printf("ButtonClass\n");
	    for(loop2=1; loop2<=but_state->num_buttons; loop2++) {
	      //printf("\tbutton[%d]=%s\n", loop2,
		     //(but_state->buttons[loop2 / 8] & (1 << (loop2 % 8))) ? "down" : "up" );
	      if (but_state->buttons[loop2 / 8] & (1 << (loop2 % 8)))
		      return true;
	    }
	    break;

	  case KeyClass:
	    //key_state = (XKeyState *) cls;
	    //printf("KeyClass\n");
	    //for(loop2=0; loop2<key_state->num_keys; loop2++) {
	      //printf("\tkey[%d]=%s\n", loop2,
		     //(key_state->keys[loop2 / 8] & (1 << (loop2 % 8))) ? "down" : "up" );
	    //}

	    break;

	  }
	  cls = (XInputClass *) ((char *) cls + cls->length);
	}

	return false;
}
