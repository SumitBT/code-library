
import java.awt.*;
import java.awt.event.*;
import java.awt.event.MouseEvent;
import java.applet.Applet;


public class AppletMouseXY extends Applet implements MouseListener,MouseMotionListener {
int x,y;
String str = "";
public void init()
{
	addMouseListener(this);
	addMouseMotionListener(this);
}
public void mousePressed(MouseEvent e)
{
	x= e.getX();
	y = e.getY();
	str = "Mouse Pressed";
	repaint();
}	
public void mouseReleased(MouseEvent e)
{
	x= e.getX();
	y = e.getY();
	str = "Mouse Released";
	repaint();
}
public void mouseClicked (MouseEvent e)
{
	x= e.getX();
	y = e.getY();
	str = "Mouse Clicked";
	repaint();
}

public void mouseExcited(MouseEvent e)
{
	x= e.getX();
	y = e.getY();
	str = "Mouse Excited";
	repaint();
}
public void mouseMoved(MouseEvent e)
{
	x= e.getX();
	y = e.getY();
	str = "Mouse Moved";
	repaint();
}	
public void mouseDragged(MouseEvent e)
{
	x= e.getX();
	y = e.getY();
	str = "Mouse Dragged";
	repaint();
}
public void paint(Graphics g)
{
	g.setFont(new Font("Monospaced",Font.BOLD,20));
	g.fillOval(x, y, 10, 10);
	g.drawString(x+","+y,x+10,y-10);
	g.drawString(str,x+10,y+20);
	showStatus(str+"at"+x+","+y);
}
public void mouseEntered(MouseEvent e) {
	// TODO Auto-generated method stub
	
}
public void mouseExited(MouseEvent e) {
	// TODO Auto-generated method stub
	
}
}

