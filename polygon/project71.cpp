#include<iostream>
#include<string>
#include <vector>
#include<math.h>
using namespace std;
class point
{
private:
float x,y;
public:
	//float x,y;
	point()
	{x=0;y=0;
	}
	void set_x(float x1)
	{
		x=x1;
	}
	void set_y(float y1)
	{
		y=y1;
	}
	float get_x()
	{
		return x;
	}
	float get_y()
	{
		return y;
	}
	float distance (point p)
	{
		float d;
		d=sqrt(pow(x-p.x,2)+pow(y-p.y,2));
		return d;
	}
	void printp(){
		cout<<"("<<x<<","<<y<<")"; 
	}
	float slope(point f)
	{
		float s;
		s=(f.y-y)/(f.x-x);
		return s;
	}
};
class polygon
{
private:
	point p[100];
	int npoints;
public:
	polygon()
	{
		npoints=0;
	}
	void set_npoints(int n)
	{
		npoints=n;
	}
	int get_npoints()
	{
		return npoints;
	}
	void set_p(point r ,int intex)
	{
		p[intex]=r;
	}
	point get_p(int inte)
	{
		return p[inte];
	}
	float get_perimeter()
	{
		float d=0;
		for(int i=0;i<npoints;i++)
		{
			if(i==npoints)
				d+=p[i].distance(p[0]);
			else
				d+=p[i].distance(p[i+1]);
		}
		return d;
	}
	void printg()
	{
		for(int e=0; e<npoints; e++)
		{
			p[e].printp();
			if(e<npoints-1)
			cout<<",";
		}
		cout<<"\n";
			
	}
	int redundant()
	{
	int total=0; float s=0;;
	for(int o=0;o<npoints;o++) 
{
		for(int e=o+1;e<npoints;e++)
		{
			if(p[o].get_x()==p[e].get_x()&&p[o].get_y()==p[e].get_y())
			{ 
				total=total+1;
			npoints=npoints-1;
		for(int u=e;u<=npoints;u++)
		{
			p[u].set_x(p[u+1].get_x());p[u].set_y(p[u+1].get_y());
		}
	             }
	}
}  

	if(p[0].get_x()==p[npoints].get_x()&&p[0].get_y()==p[npoints].get_y())
	{
		total=total+1;
	//p[get_npoints()].set_x(0);
	//p[get_npoints()].set_y(0);
	npoints=npoints-1;
	}

	for(int i=0;i<npoints;i++)
	{
	//	if(i+1>npoints)
	//		break ;

	if(p[i].slope(p[i+1])==p[i].slope(p[i+2])&&(p[i].slope(p[i+1])==p[i+1].slope(p[i+2])))
	{
		npoints=npoints-1;
		total=total+1;
		for(int u=i;u<=npoints;u++)
		{
			p[u+1].set_x(p[u].get_x());p[u+1].set_y(p[u].get_y());
		}
	}

	}
	if(p[npoints-1].slope(p[0])==p[npoints].slope(p[0])&&(p[npoints-1].slope(p[npoints])==p[npoints].slope(p[0])))
	{
	//if(p[0].get_x()==p[npoints-1].get_x()&&p[0].get_y()==p[npoints-1].get_y())
	//{
		total=total+1;
	npoints=npoints-1;
	}
	//p[get_npoints()-1].set_x(0);
	//p[get_npoints()-1].set_y(0);
	//npoints=npoints-1;
	//}

		return total;
	}

	int search(point p1)
	{
		int e=0;
		
		for(int r=0;r<npoints;r++)
		{
			//u=p[r];
		if(p1.get_x()==p[r].get_x()&&p1.get_y()==p[r].get_y())
			e=1;
		
			
		}
		return e;
	}

	void search_p(polygon g1,int &com,point &p3)
	{
		 
		//point p3;
		for(int i=0;i<npoints;i++)
		{
		for(int j=0;j<g1.npoints;j++)
		{
		if(p[i].get_x()==g1.get_p(j).get_x()&&p[i].get_y()==g1.get_p(j).get_y())
		{
			com=1;
			p3= p[i];
			//return p3; 
		}
		}
		}
	}
	int istriangles()
	{
		if(npoints==3)
			return 1;
		else 
			return 0;
	
	}

	int isrectangles()
	{
		if(npoints==4)
		{
		if(p[0].distance(p[1])==p[2].distance(p[3])&&p[1].distance(p[2])==p[0].distance(p[3]))
			return 1;
		}
		else 
			return 0;
	}

	int istrapezoid()
	{
		if(npoints==4)
		{
			if(p[0].slope(p[1])==p[3].slope(p[2])&&p[0].distance(p[1])!=p[3].distance(p[2]))
				return 1;
		
		}
		else 
			return 0;
	
	}
};
class splitstring : public string {
    vector<string> flds;
public:
    splitstring(string s) : string(s) { };
    vector<string>& split(char delim, int rep=0);
};

vector<string>& splitstring::split(char delim, int rep) {
    if (!flds.empty()) flds.clear();  // empty vector if necessary
    string work = data();
    string buf = "";
    int i = 0;
    while (i<work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
};
//////////////////////////////⁄·‘«‰ «ﬁÿ⁄ «· ‰’ «·Ì „Ã„Ê⁄Â „‰ «·«‘ﬂ«· 
void split(string polygons[],string s1,int &Number_Polygons ) 
{
	int l,r,simy,simy2=0,y2,po ;
	string m ,Q[100],w[100],p;
	l = s1.length();
	
	m=s1.substr(10,l);
	r=m.length();
	for(int y=0;y<r;y++)
	{
	simy=m.find(";",0); 
	if(simy==-1)
		break;
	p=m.substr(simy2,simy);	
	polygons[y]=p;
	
	m=m.substr(simy+1);
	y2=y;
	//cout<<polygons[y]<<"\n";
	}
	po=m.find("]");
	polygons[y2+1]=m.substr(0,po);
	Number_Polygons=y2+2;
	 
};
void convert(string polygons[],polygon go[],int Number_Polygons )
{
	float x1,y1;
	point p;
		int location_x,location_y,Counter=0,t,co=0;
	string x,y;
	std::string::size_type pos_9,pos_coma,pos_0;
	for(int ii=0;ii<Number_Polygons;ii++)
	{
		t=0;
		Counter=0;
		co=0;
		t=polygons[ii].length();  
	while(Counter<=t )
	{
	pos_9=polygons[ii].find("(",Counter);// ÕœÌœ „ﬂ«‰ «· )
	pos_coma=polygons[ii].find(",",pos_9); // ÕœÌœ „ﬂ«‰ Ê
	pos_0=polygons[ii].find(")",pos_coma);//  ÕœÌœ „ﬂ«‰ «· (
	location_x=(pos_coma)-(pos_9)-1;//  ⁄·‘«‰ «·Õœœ ÿÊ· «·‰’ «·Ì ⁄«Ê“ «ﬁÿ⁄Â ( ÿÊ· «· X)
	location_y=(pos_0)-(pos_coma)-1;// ÿÊ· «·‰’ » «⁄ «·y
     x=polygons[ii].substr(pos_9+1,location_x);// ÊÂ‰« «‰« »Œ“‰ ﬁÌ„ «· «·«ﬂ”
	y=polygons[ii].substr(pos_coma+1,location_y);// ÊÂ‰« »Œ“‰ ﬁÌ„ «· Y
	Counter=pos_0+1;// ⁄·‘«‰ Ìﬂ—— «·⁄„·ÌÂ ⁄·Ì ﬂ· «· point 
	//cout<<e<<"\n"<<n<<"\n"<<uu<<"\n"<<x<<"\n"<<y;
	x1= atof(x.c_str());
	y1= atof(y.c_str());
	p.set_x(x1);
	p.set_y(y1);
	//cout<<x1<<"\n"<<y1<<"\n";
	go[ii].set_p(p,co);
	co++;
	if(Counter>=t)
		break ;
	} 

	//cout<<go[ii].get_p(0).get_x()<<"\n";
	go[ii].set_npoints(co);
	}
};

	/////////////////////////////////////
int main(){
	point p,q;
	polygon g[100],gp;
	int e =1 , Number_Polygons,n;
	float a=0,min_x,min_y,max_x,max_y;
	string s1,polygons[100],Q,L2;
	getline(cin,s1);
		split(polygons,s1,Number_Polygons); 
		convert(polygons,g,Number_Polygons);
			max_x=g[0].get_p(0).get_x ();
		for(int i=1;i<Number_Polygons;i++){
		 for(int y=1 ;y<g[i].get_npoints();y++){
			 if(max_x<g[i].get_p(y).get_x()){
				 max_x=g[i].get_p(y).get_x();}
		}
	}
			min_x=g[0].get_p(0).get_x ();
		for(int i=1;i<Number_Polygons;i++){
		 for(int y=1 ;y<g[i].get_npoints();y++){
			 if(min_x>g[i].get_p(y).get_x()){
				 min_x=g[i].get_p(y).get_x();}
		}
	}
	
			min_y=g[0].get_p(0).get_y ();
		for(int i=1;i<Number_Polygons;i++){
		 for(int y=1 ;y<g[i].get_npoints();y++){
			 if(min_y>g[i].get_p(y).get_y()){
				 min_y=g[i].get_p(y).get_y();}
		}
	}

			max_y=g[0].get_p(0).get_y ();
		for(int i=1;i<Number_Polygons;i++){
		 for(int y=1 ;y<g[i].get_npoints();y++){
			 if(max_y<g[i].get_p(y).get_y()){
				 max_y=g[i].get_p(y).get_y();}
		}
	}
	
		////////////////////////////////////////////////////////////
		while(1)
		{
	getline(cin,Q);
	if(Q== "Number_Polygons")
		cout<<Number_Polygons<< endl; 
	
	if(Q=="Quit")
		break;
	if(Q=="Total_Number_Points"){
	int	total=g[0].get_npoints();
		for(int i=1;i<Number_Polygons;i++)
			total=total+g[i].get_npoints();
		cout<<total<<"\n";
	}
	if(Q=="Minimum_X")
	{
		
		cout<<min_x<<"\n";
}

		if(Q=="Minimum_Y")
	{
		
	
		cout<<min_y<<"\n";
}
	
			if(Q=="Maximum_X")
	{
		
	
		cout<<max_x<<"\n";
}

		if(Q=="Maximum_Y")
	{
		cout<<max_y<<"\n";
}
		if(Q=="Enclosing_Rectangle")
		{
			cout<<"("<<min_x<<","<<min_y <<")"<<","<<"("<<max_x<<","<<min_y<<")"<<","<<"("<<max_x<<","<<max_y<<")"<<","<<"("<<min_x<<","<<max_y<<")"<<"\n"; 
		}

		if(Q=="Total_Redundant_Points")
		{
			int red=0;
			for(int i=0;i<Number_Polygons ;i++)
			{
			red=red+g[i].redundant();
			red=red+g[i].redundant();
			}
			cout<<red<<"\n";
		}

		if(Q.substr(0,15)=="Polygon_Points ")
		{
			g[atoi(Q.substr(15).c_str())-1].printg();
		}

		if(Q.substr(0,15)=="Point_Polygons ")
		{
			point p1;
			int lx,ly,f_9,f_com,f_0,tt=0;
			//string ww;
			//ww=Q.substr(15);
			f_9=Q.find("(");
			f_com=Q.find(",");
			f_0=Q.find("(");
			lx=(f_com)-(f_9)-1;
			ly=(f_0)-(f_com)-1;
			p1.set_x(atof(Q.substr(f_9+1,lx).c_str()));
			p1.set_y(atof(Q.substr(f_com+1,ly).c_str()));
			int con=0;
			for(int i=0;i<Number_Polygons;i++)
			{
			if(g[i].search(p1)==1)
				con++;
			}
			for(int i=0;i<Number_Polygons;i++)
			{
			if(g[i].search(p1)==1){
				cout<<i+1;
				tt++;
				con--;
				if(con>0)
					cout<<"," ;
			}
			}
			if(tt==0)
					cout<<"none";
			cout<<"\n";

		}

		if(Q.substr(0,26)=="List_Polygons_Points More ")
		{
			int op3,tt=0;
		op3=atoi(Q.substr(26).c_str());
		int con3=0;
		for(int i=0;i<Number_Polygons;i++){
			if(op3<g[i].get_npoints())
				con3++;
		}
		for(int i=0;i<Number_Polygons;i++){
				if(op3<g[i].get_npoints()){
					cout<<i+1;
					tt++ ;
				con3--;
				if(con3>0)
					cout<<"," ;}
			}
		if(tt==0)
					cout<<"none";
			cout<<"\n";

		}

		if(Q.substr(0,26)=="List_Polygons_Points Less ")
		{
			int op3,tt=0;
		op3=atoi(Q.substr(26).c_str());
		int con3=0;
		for(int i=0;i<Number_Polygons;i++){
			if(op3>g[i].get_npoints())
				con3++;
		}
		for(int i=0;i<Number_Polygons;i++){
				if(op3>g[i].get_npoints()){
					cout<<i+1;
					tt++;
				con3--;
				if(con3>0)
					cout<<"," ;}
			}
		if(tt==0)
					cout<<"none";
			cout<<"\n";

		}

		if(Q.substr(0,27)=="List_Polygons_Points Equal ")
		{
			int op3,tt=0;
		op3=atoi(Q.substr(27).c_str());
		int con3=0;
		for(int i=0;i<Number_Polygons;i++){
			if(op3==g[i].get_npoints())
				con3++;
		}
		for(int i=0;i<Number_Polygons;i++){
				if(op3==g[i].get_npoints()){
					cout<<i+1;
					tt++;
				con3--;
				if(con3>0)
					cout<<"," ;}
			}
		if(tt==0)
					cout<<"none";
			cout<<"\n";

		}
		/////////////////////////////////////operation6,7and8 in level2
			polygon go;
			int com=0,com2=0;
			point p8;
			go.set_npoints(50);
			for(int i=0;i<Number_Polygons-1 ;i++)
			{
				for(int j=i+1;j<Number_Polygons;j++) 
			{
					g[i].search_p(g[j],com,p8);
				if(com==1)
					{
						g[i].search_p(g[j],com,p8);
						go.set_p(p8,com2);
						com2++;
				com=0;
					}
			}
		}
			go.redundant();
			go.redundant();
			go.redundant();
			int oo[20][20],colum=0,row=0,re;
			for(int o=0;o<7;o++){for(int u=0;u<7;u++){oo[o][u]=-1;}}
			for(int j=0;j<go.get_npoints()-1;j++)
			{
				for(int i=0;i<Number_Polygons;i++)
				{
					if(g[i].search(go.get_p(j))==1)
					{
						oo[j][colum]=i;
						colum++;
					}
			}
			colum=0;
				
		}
		if(Q.substr(0,26)=="List_Points_Polygons More ")
		{
	
			int n,dr=0,tt=0;
			n=atoi(Q.substr(26).c_str());
			int cont=0;
		for(int r=0; r<go.get_npoints()-1;r++)
			{
				for(int e=0;e<7;e++)
				{
					if(oo[r][e]>0){
						cont++;}
			}
				if(n<cont)
					dr++;
				cont=0;
		}

		for(int r=0; r<go.get_npoints()-1;r++)
			{
				for(int e=0;e<7;e++)
				{
					if(oo[r][e]>0){
						cont++;}
			}
				if(n<cont){
					dr--;
					go.get_p(r).printp();
					tt++;
					if(dr>0)
						cout<<",";}
				cont=0;
		}
		if(tt==0)
					cout<<"none";
			cout<<"\n";
	}

				if(Q.substr(0,26)=="List_Points_Polygons Less ")
		{

			int n,dd=0;
			n=atoi(Q.substr(26).c_str());
			int cont=0,tt=0;
			for(int r=0; r<go.get_npoints()-1;r++)
			{
				for(int e=0;e<7;e++)
				{
					if(oo[r][e]>0){
						cont++;}
			}
				if(n>cont){
					dd++;

				}
				cont=0;
		}
				for(int r=0; r<go.get_npoints()-1;r++)
			{
				for(int e=0;e<7;e++)
				{
					if(oo[r][e]>0){
						cont++;}
			}
				if(n>cont){
					dd--;
					go.get_p(r).printp();
					tt++;
					if(dd>0)
						cout<<",";
				}
				cont=0;
		}
				if(tt==0)
					cout<<"none";


			cout<<"\n";
	}
						if(Q.substr(0,27)=="List_Points_Polygons Equal ")
		{

			int n,eq=0,tt=0;
			n=atoi(Q.substr(27).c_str());
			int cont=0;
			for(int r=0; r<go.get_npoints()-1;r++){
				for(int e=0;e<7;e++)
				{
					if(oo[r][e]>0){
						cont++;}
			}
				if(n==cont)
					eq++;
			
				cont=0;
		}
			for(int r=0; r<go.get_npoints()-1;r++){
				for(int e=0;e<7;e++)
				{
					if(oo[r][e]>0){
						cont++;}
			}
				if(n==cont)
				{
					eq--;
					go.get_p(r).printp();
					tt++;
					if(eq>0)
						cout<<",";
				}
			
				cont=0;
		}
			if(tt==0)
					cout<<"none";

			cout<<"\n";
	}

///////////////////////////////////////////////////////////////////////

			if(Q.substr(0,18)=="Polygon_Perimeter ")
			{
			cout<<g[atoi(Q.substr(18).c_str())+1].get_perimeter()<<"\n"; 
			}


			if(Q=="List_Triangles")
			{
				int con5=0,tt=0;
				for(int i=0; i<Number_Polygons;i++)
				{
					if(g[i].istriangles()==1)
					con5++;
				}
				for(int i=0;i<Number_Polygons;i++)
				{
					if(g[i].istriangles()==1)
					{
						cout<<i+1;
						tt++;
						con5--;
						if(con5>0)
							cout<<",";
					}
				}
			if(tt==0)
					cout<<"none";
			cout<<"\n";
			}
		
			if(Q=="List_Rectangles")
			{
				int con6=0,tt=0;
				for(int i=0;i<Number_Polygons;i++)
				{
					if(g[i].isrectangles()==1)
						con6++;
				}
				for(int i=0;i<Number_Polygons;i++)
				{
					if(g[i].isrectangles()==1)
					{
						con6--;
						cout<<i+1;
					tt++;
					if(con6>0)
						cout<<",";
					}
				}
				if(tt==0)
					cout<<"none";
				cout<<"\n";
			}
			
			if(Q=="List_Trapezoid")
			{
				int con6=0,tt=0;
				for(int i=0;i<Number_Polygons;i++)
				{
					if(g[i].istrapezoid()==1)
						con6++;
				}
				for(int i=0;i<Number_Polygons;i++)
				{
					if(g[i].istrapezoid()==1)
					{
						cout<<i+1;
					tt++;
					con6--;
					if(con6>0)
						cout<<",";
					}
				}
				if(tt==0)
					cout<<"none";
				cout<<"\n";
			}

//////////////////////////////////////////////////////////// level 3
			
	}system("pause");
	return 0;

}