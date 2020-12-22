#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//������ ����
#define x 9
#define y 9
//�ⱸ ����
#define exit_a 5
#define exit_b 8
int Maze[x][y] = { {0,} };

typedef struct Pos {
    int a, b;
} Pos;
queue<Pos>point;//�Ա����� �ⱸ�� ��Ʈ�� ã�� Point
vector<Pos>trc;//�Ա����� �ⱸ ��Ʈ�� ��ǥ�� ã�� Trace
Pos dxy[4] = { {0,1},{-1,0},{0,-1},{1,0} };
int initMaze() 
{
    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, "Maze.txt", "rt");
    if (err)
    {
        printf("Failed to open!\n");
        return 0;
    }
    int r = 0;
    char buf[256];
    while (fgets(buf, 255, fp))
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = '\0';
        }
        string str = buf;

        int c = 0;
        int idx = 0;
        while (1)
        {
            int idx1 = str.find(',', idx);
            if (idx1 == string::npos)
            {
                string tstr = str.substr(idx);
                Maze[r][c] = atoi(tstr.c_str());
                break;
            }
            string tstr = str.substr(idx, idx1 - idx);
            Maze[r][c] = atoi(tstr.c_str());
            idx = idx1 + 1;
            c++;
        }
        r++;
    }
    fclose(fp);
    return 1;
}

int main() {
    int s = NULL;
    if (initMaze() != 1) return 1;
    Maze[0][0] = -1;//������ ����

    point.push({ 0, 0 });//enqueue
    while (!point.empty()) {
        Pos t = point.front();
        point.pop();
        for (int i = 0; i < 4; i++) {//3�� 12�� 9�� 6�� ������ �ֺ��� Ž���ϰ� ������ ������ų �� ���� ��ǥ�� �����͸� -1�� ����
            int aa = t.a + dxy[i].a;
            int bb = t.b + dxy[i].b;
            if (aa >= 0 && bb >= 0 && aa < x && bb < y && Maze[aa][bb] == 0) {
                point.push({ aa,bb });//���ǿ� ������ enqueue
                Maze[aa][bb] = Maze[t.a][t.b] - 1;
                if (aa == exit_a && bb == exit_b) {
                    s = point.size();
                    for (int i = 0; i < s; i++) {
                        point.pop();
                    }
                    break;
                }
            }
        }
    }
    if (!s) printf("No Exit!");
    else
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) printf("[%3d]", Maze[i][j]);
            printf("\n");
        }
    //----------------------------------------------------------------------------------------------------------
    int idx = Maze[exit_a][exit_b];
    int a = exit_a;
    int b = exit_b;
    trc.push_back({ a,b });
    int aa;
    int bb;
    while (idx != -1)
    {
        for (int i = 0; i < 4; i++) {
            aa = a + dxy[i].a;
            bb = b + dxy[i].b;
            if (aa >= 0 && bb >= 0 && aa < x && bb < y && Maze[aa][bb] == (idx + 1)) {
                trc.push_back({ aa,bb });
                a = aa;
                b = bb;
                idx += 1;
                break;
            }
        }
    }
    for (auto t : trc)
    {
        printf("[%d,%d]\n", t.a, t.b);
        Maze[t.a][t.b] = 77;
    }
    trc.clear();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (Maze[i][j] == 77)printf("��");
            else printf("��");
        }
        printf("\n");
    }
}