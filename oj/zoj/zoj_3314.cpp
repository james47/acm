#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct que{
	int x, y;
} q[100000];
string ch[60][10];
string map[400];
int vis[340][340];
int n, m, ll, rr, uu, dd, cnt;
int L[60], R[60], U[60], D[60];
bool ans[60];
bool vv[30][30];

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1},
    dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
void floodfill(int x, int y, int &ll, int &rr, int &uu, int &dd)
{
	uu = dd = x;
	ll = rr = y;
	vis[x][y] = cnt;
	int head, tail;
	head = tail = 0;
	q[head].x = x;
	q[head].y = y;
	tail ++;
	while (head < tail)
	{
		int xx = q[head].x, yy = q[head].y;
		head ++;
		for (int i = 0; i < 8; i++){
			int xt = xx + dx[i], yt = yy + dy[i];
			if (xt < 0 || yt < 0 || xt > n-1 || yt > m-1) continue;
			if (map[xt][yt] == 'M' && !vis[xt][yt]){
				vis[xt][yt] = cnt;
				ll = min(ll, yt);
				rr = max(rr, yt);
				uu = min(uu, xt);
				dd = max(dd, xt);
				q[tail].x = xt;
				q[tail++].y = yt;
			}
		}
	}
}
void floodfill2(int x, int y, int &ll, int &rr, int &uu, int &dd, int pos)
{
				ll = min(ll, y);
				rr = max(rr, y);
				uu = min(uu, x);
				dd = max(dd, x);
	int head, tail;
	head = tail = 0;
	q[head].x = x;
	q[head].y = y;
	tail ++;
	while (head < tail)
	{
		int xx = q[head].x, yy = q[head].y;
		vv[xx][yy] = true;
		head ++;
		for (int i = 0; i < 8; i++){
			int xt = xx + dx[i], yt = yy + dy[i];
			if (xt < 1 || yt < 0 || xt > 7 || yt > 15) continue;
			if (ch[pos][xt][yt] == 'M' && !vv[xt][yt]){
				vv[xt][yt] = true;
				ll = min(ll, yt);
				rr = max(rr, yt);
				uu = min(uu, xt);
				dd = max(dd, xt);
				q[tail].x = xt;
				q[tail++].y = yt;
			}
		}
	}
}

bool check(int pos, int ll, int rr, int uu, int dd)
{
	for (int i = uu; i <= dd; i++)
		for (int j = ll; j <= rr; j++){
			int xx = U[pos] + i - uu, yy = L[pos] + j - ll;
			if (map[i][j] == 'M' && vis[i][j] == cnt){
				if (ch[pos][xx][yy] != 'M') return false;
			}
			if (ch[pos][xx][yy] == 'M' && vis[i][j] != cnt){
				return false;
			}
		}
	return true;
}
int main()
{
 ch[1][1] ="111111MMM1111111";  ch[2][1] = "1MMMMMMMMMMM1111";  ch[3][1] = "11111MMMMMMMM111";      
 ch[1][2] ="11111MM1MM111111";  ch[2][2] = "1MM11111111MM111";  ch[3][2] = "111MM1111111MM11";      
 ch[1][3] ="1111MM111MM11111";  ch[2][3] = "1MM11111111MM111";  ch[3][3] = "11MM111111111MM1";      
 ch[1][4] ="111MMMMMMMMM1111";  ch[2][4] = "1MMMMMMMMMMM1111";  ch[3][4] = "11MM111111111111";      
 ch[1][5] ="11MM1111111MM111";  ch[2][5] = "1MM11111111MM111";  ch[3][5] = "11MM111111111MM1";      
 ch[1][6] ="1MMM11111111MM11";  ch[2][6] = "1MM11111111MM111";  ch[3][6] = "111MM1111111MM11";      
 ch[1][7] ="1MM1111111111MM1";  ch[2][7] = "1MMMMMMMMMMM1111";  ch[3][7] = "11111MMMMMMMM111";      

  ch[4][1] ="1MMMMMMMMMMM1111";  ch[5][1] ="1MMMMMMMMMMMM111"; ch[6][1] ="1MMMMMMMMMMMMM11";	
  ch[4][2] ="1MM111111111MM11";  ch[5][2] ="1MM1111111111111"; ch[6][2] ="1MM1111111111111";
  ch[4][3] ="1MM1111111111MM1";  ch[5][3] ="1MM1111111111111"; ch[6][3] ="1MM1111111111111";
  ch[4][4] ="1MM1111111111MM1";  ch[5][4] ="1MMMMMMMMMMMM111"; ch[6][4] ="1MMMMMMMMMMMMM11";
  ch[4][5] ="1MM1111111111MM1";  ch[5][5] ="1MM1111111111111"; ch[6][5] ="1MM1111111111111";
  ch[4][6] ="1MM111111111MM11";  ch[5][6] ="1MM1111111111111"; ch[6][6] ="1MM1111111111111";
  ch[4][7] ="1MMMMMMMMMMM1111";  ch[5][7] ="1MMMMMMMMMMMM111"; ch[6][7] ="1MM1111111111111";

  ch[7][1] ="11111MMMMMMMM111";   ch[8][1] ="1MM111111111MM11";   ch[9][1] ="11111MMMMMM11111";      
  ch[7][2] ="111MM1111111MM11";   ch[8][2] ="1MM111111111MM11";   ch[9][2] ="1111111MM1111111";      
  ch[7][3] ="11MM111111111MM1";   ch[8][3] ="1MM111111111MM11";   ch[9][3] ="1111111MM1111111";      
  ch[7][4] ="11MM111111111111";   ch[8][4] ="1MMMMMMMMMMMMM11";   ch[9][4] ="1111111MM1111111";      
  ch[7][5] ="11MM111111MMMMM1";   ch[8][5] ="1MM111111111MM11";   ch[9][5] ="1111111MM1111111";      
  ch[7][6] ="111MM1111111MM11";   ch[8][6] ="1MM111111111MM11";   ch[9][6] ="1111111MM1111111";      
  ch[7][7] ="11111MMMMMMMMM11";   ch[8][7] ="1MM111111111MM11";   ch[9][7] ="11111MMMMMM11111";      

  ch[10][1] ="1111MMMMMMMM1111";   ch[11][1] ="11MM111111MMM111";   ch[12][1] ="11MM111111111111";
  ch[10][2] ="1111111MM1111111";   ch[11][2] ="11MM11111MMM1111";   ch[12][2] ="11MM111111111111";
  ch[10][3] ="1111111MM1111111";   ch[11][3] ="11MM111MMM111111";   ch[12][3] ="11MM111111111111";
  ch[10][4] ="1111111MM1111111";   ch[11][4] ="11MMMMM111111111";   ch[12][4] ="11MM111111111111";
  ch[10][5] ="111MM11MM1111111";   ch[11][5] ="11MM111MMM111111";   ch[12][5] ="11MM111111111111";
  ch[10][6] ="111MMM1MM1111111";   ch[11][6] ="11MM11111MMM1111";   ch[12][6] ="11MM111111111111";
  ch[10][7] ="11111MMMM1111111";   ch[11][7] ="11MM111111MMMM11";   ch[12][7] ="11MMMMMMMMMMMM11";

  ch[13][1] ="1MM1111111111MM1";   ch[14][1] ="1MMM111111111MM1";   ch[15][1] ="11111MMMMMM11111";     
  ch[13][2] ="1MMMM111111MMMM1";   ch[14][2] ="1MMMM11111111MM1";   ch[15][2] ="111MMM1111MMM111";     
  ch[13][3] ="1MM1MM1111MM1MM1";   ch[14][3] ="1MM1MM1111111MM1";   ch[15][3] ="11MMM111111MMM11";     
  ch[13][4] ="1MM11MMMMM111MM1";   ch[14][4] ="1MM11MM111111MM1";   ch[15][4] ="1MM1111111111MM1";     
  ch[13][5] ="1MM1111M11111MM1";   ch[14][5] ="1MM1111MM1111MM1";   ch[15][5] ="11MMM111111MMM11";     
  ch[13][6] ="1MM1111111111MM1";   ch[14][6] ="1MM111111MMM1MM1";   ch[15][6] ="111MMM1111MMM111";     
  ch[13][7] ="1MM1111111111MM1";   ch[14][7] ="1MM11111111MMMM1";   ch[15][7] ="11111MMMMMM11111";     

 ch[16][1] ="1MMMMMMMMMMM1111";   ch[17][1] ="11111MMMMMM11111";   ch[18][1] ="1MMMMMMMMMMM1111";
 ch[16][2] ="1MM111111111MM11";   ch[17][2] ="111MMM1111MMM111";   ch[18][2] ="1MM111111111MM11";
 ch[16][3] ="1MM1111111111MM1";   ch[17][3] ="11MMM111111MMM11";   ch[18][3] ="1MM1111111111MM1";
 ch[16][4] ="1MM111111111MM11";   ch[17][4] ="1MM1111111111MM1";   ch[18][4] ="1MM111111111MM11";
 ch[16][5] ="1MMMMMMMMMMM1111";   ch[17][5] ="11MMM1MMMM1MMM11";   ch[18][5] ="1MMMMMMMMMMM1111";
 ch[16][6] ="1MM1111111111111";   ch[17][6] ="111MMM11MMMMM111";   ch[18][6] ="1MM11111111MM111";
 ch[16][7] ="1MM1111111111111";   ch[17][7] ="111111MMMM1MMMM1";   ch[18][7] ="1MM111111111MMM1";


  ch[19][1] ="1111MMMMMMMM1111";   ch[20][1] ="11MMMMMMMMMMMM11";   ch[21][1] ="1MM1111111111MM1";     
  ch[19][2] ="111MM1111111MM11";   ch[20][2] ="11MMMMMMMMMMMM11";   ch[21][2] ="1MM1111111111MM1";     
  ch[19][3] ="11MMM1111111MMM1";   ch[20][3] ="1111111MM1111111";   ch[21][3] ="1MM1111111111MM1";     
  ch[19][4] ="1111MMMMM1111111";   ch[20][4] ="1111111MM1111111";   ch[21][4] ="1MM1111111111MM1";     
  ch[19][5] ="1MMM111MMMM11111";   ch[20][5] ="1111111MM1111111";   ch[21][5] ="1MMM11111111MMM1";     
  ch[19][6] ="111MMM11111MMM11";   ch[20][6] ="1111111MM1111111";   ch[21][6] ="1MMM11111111MMM1";     
  ch[19][7] ="11111MMMMMMM1111";   ch[20][7] ="1111111MM1111111";   ch[21][7] ="111MMMMMMMMMM111";     


 ch[22][1] ="1MMMM111111MMMM1";   ch[23][1] ="1MM1111111111MM1";   ch[24][1] ="11MMM111111MMM11";
 ch[22][2] ="11MMM111111MMM11";   ch[23][2] ="1MM1111111111MM1";   ch[24][2] ="111MMM1111MMM111";
 ch[22][3] ="11MMM111111MMM11";   ch[23][3] ="11MM111MM111MM11";   ch[24][3] ="1111MMM11MMM1111";
 ch[22][4] ="111MMM1111MMM111";   ch[23][4] ="11MM111MM111MM11";   ch[24][4] ="111111MMMM111111";
 ch[22][5] ="1111MMM11MMM1111";   ch[23][5] ="11MM111MM111MM11";   ch[24][5] ="1111MMM11MMM1111";
 ch[22][6] ="11111MM11MM11111";   ch[23][6] ="11MM1MM11MM1MM11";   ch[24][6] ="111MMM1111MMM111";
 ch[22][7] ="111111MMMM111111";   ch[23][7] ="111MMM1111MMM111";   ch[24][7] ="11MMM111111MMM11";


  ch[25][1] ="11MMM111111MMM11";   ch[26][1] ="111MMMMMMMMMM111";   
  ch[25][2] ="111MMM1111MMM111";   ch[26][2] ="1111111111MM1111";   
  ch[25][3] ="1111MMM11MMM1111";   ch[26][3] ="111111111MM11111";   
  ch[25][4] ="111111MMMM111111";   ch[26][4] ="11111111MM111111";   
  ch[25][5] ="1111111MM1111111";   ch[26][5] ="111111MM11111111";   
  ch[25][6] ="1111111MM1111111";   ch[26][6] ="11111MM111111111";   
  ch[25][7] ="1111111MM1111111";   ch[26][7] ="111MMMMMMMMMMM11";

	string tmp;
	char xx;
	for (int i = 1; i <= 26; i++){
	        for (int j = 1; j <= 7; j++){
	      	  tmp = ch[i][j];
	      	  for (int k = 0, l = tmp.length()-1; k < l; k++, l--){
	      		  xx = tmp[k]; tmp[k] = tmp[l]; tmp[l] = xx;
	      	  }
	      	  ch[i+26][8-j] = tmp;
	        }
	}
	for (int i = 1; i <= 52; i++){
		ll = 300, rr = 0, uu = 300, dd = 0;
		memset(vv, 0, sizeof(vv));
		for (int ii = 1; ii <= 7; ii++)
			for (int jj = 0; jj < 16; jj++){
				if (ch[i][ii][jj] == 'M'){
					floodfill2(ii, jj, ll, rr, uu, dd, i);
					break;
				}
			}

		L[i] = ll;
		R[i] = rr;
		U[i] = uu;
		D[i] = dd;
	}
	/*
	for (int i = U[25]; i <= D[25]; i++){
		for (int j = L[25]; j <= R[25]; j++)
			printf("%c", ch[25][i][j]);
		printf("\n");
	}
	for (int i = U[25+26]; i <= D[25+26]; i++){
		for (int j = L[25+26]; j <= R[25+26]; j++)
			printf("%c", ch[25+26][i][j]);
		printf("\n");
	}
	*/
	/*
	for (int i = 26+6; i <= 26 + 6; i++){
	        for (int j = 1; j <= 7; j++){
	      	  for (int k = 0; k < 16; k ++)
	      	  	cout << ch[i][j][k];
	        	cout << endl;
	        }
	        cout << endl;
	}
	*/
	while(scanf("%d%d", &n, &m)!= EOF)
	{
		for (int i = 0; i < n; i++) cin >> map[i];
		memset(vis, 0, sizeof(vis));
		memset(ans, 0, sizeof(ans));
		cnt = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				if (map[i][j] == 'M' && !vis[i][j]){
					floodfill(i, j, ll, rr, uu, dd);
				/*	
					for (int ii = uu; ii <= dd; ii++){
						for (int jj = ll; jj <= rr; jj++)
							printf("%c", map[ii][jj]);
						printf("\n");
					}
				*/

					for (int k = 1; k <= 52; k++){
						if (check(k, ll, rr, uu, dd)){
							ans[k] = true;
							break;
						}
					}
					cnt ++;
				}
			}
		for (int i = 1; i <= 26; i++)
			if (ans[i] || ans[i+26]) printf("%c", i+'A'-1);
		printf("\n");
	}
	return 0;
}
