#include "ChangeDoctorWin.h"

ChangeDoctorWin::ChangeDoctorWin(int x,int y,int width,int height,int id) : CWin(x,y,width,height)
{
	this->id = id;
	char str[30];
	sprintf(str,"医生ID: %d",id);


	Contorl *c1 = new CLable(15,11,5,5,"提示：修改职位");
	Contorl *c2 = new CLable(20,13,5,5,str);
	Contorl *c3 = new CLable(20,16,5,5,"职位：");
	Contorl *c4 = new CCombobox(30,15,6,3,"专家");
	Contorl *c5 = new CBun(20,18,5,3,"确认");
	Contorl *c6 = new CBun(35,18,5,3,"返回");


	CBun bun1(30,15,6,3,"专家");
	CBun bun2(30,17,6,3,"主任医生");
	CBun bun3(30,19,6,3,"副主任医师");
	CBun bun4(30,21,6,3,"主治医师");


	((CCombobox *)c4)->addBun(bun1);
	((CCombobox *)c4)->addBun(bun2);
	((CCombobox *)c4)->addBun(bun3);
	((CCombobox *)c4)->addBun(bun4);


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int ChangeDoctorWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();


	if(n == 3)
	{
		advance(p,3);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 4)
	{
		CTool::getDoctor(user);
		advance(p,3);
		strcpy(user[id]->posts,(*p)->content);
		CTool::write(user);
		PopUp tempwin(15,15,20,15,"修改成功");
		tempwin.showWin();
		tempwin.runWin();
		return 10;
	}else if(n == 5)
	{
		return 10;
	}
	return -1;
}

int ChangeDoctorWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	
	return 0;
}