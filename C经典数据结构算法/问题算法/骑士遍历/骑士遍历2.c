�����ʿ�������� 
��Ȼ�����ʿ���������ÿһ�����������������ߵ�һ������ÿһ������Ҫѡ��һ�����������������ʱ��ס���ÿһ����Ҫ��ס�����£� 
1.��ǰ��������λ�� 
2.��ǰ���Ѿ���̽����Щ�����ˣ��Ա���ݻ���ʱ�ܹ�ѡ��һ���µķ��������̽ 
����ʹ���������飬����board��ס���̵�ÿ��λ��������ĵڼ�������ģ��ⷴӳ������Ľ⣬���ڼ������ĸ�λ�á�����direction��ס�����̵�ĳ��λ���Ѿ���̽���ķ���ÿ��λ���а˸����򣬿ɰ�ĳ��˳��԰˸������ţ�Ȼ����ÿ��λ�ð����˳����̽���� 
��ȷ�����ݽṹ֮��ͬ����Ҫȷ�����漸�����⣺ 
1.������״̬�ǳ�ʼ״̬�� 
2.����ѡ��ǰ�����ܵ�·�� 
3.������ʾ��ǰ�ƽ�һ�� 
4.�������ݼ������ǰ���ĺۼ� 
��Ȼ��ʼ״̬�����̵�ÿ��λ�ö���Ϊ��0���������û�е����ÿ��λ�ö���û��ѡ���κη��򣨿ɸ�ֵMAX_DIR(=8)��ʾû��ѡ���򣩡� 
ѡ��ǰ�����ܵ�·�߾����ڵ�ǰλ��ѡ��һ��������������һ������ѡ���ʱ��ͬ����Ҫ�����Ǵӵ�0������ʼ���ǻ��Ǵ���һ�ε���һ������ʼ���ǡ�Ϊ�˷������һ������ʼ���ǣ�ʵ��������direction��ĳһλ��(curr_x, curr_y)��ֵ��ס���Ǵ���һλ��ѡ�����ĸ���ŵķ��������ģ��������׻��ݵ���һλ�ã����������ڻ��ݵ���һλ��֮����¸�һ����������̽�� 
��ǰ�ƽ�һ����Ҫ������ѡ��ķ����ƽ�����һλ�ã���ס����һλ����ѡ��ķ�����һλ���ǵڼ�������ģ�Ȼ�����Ӳ����� 
����һ����Ҫ��ǵ�ǰλ��û�е������������Ĳ�����Ϊ0����������һ������ǰλ�õ���ѡ��ķ�����������Ǽ�¼��ǰλ������Ӧ��direction�����У������ݵ���һλ�ã�Ȼ����ٲ����� 
�����������KNIGHT����װ����board��direction����ǰλ��(curr_x, curr_y)����ǰ����(step)������ʹ��last_direction����ס��һλ�õ���ǰλ����ѡ��ķ���Ϊ�˷������ѡ��һ�������ӵ�ǰ�ƽ�����һλ�ã�ʹ������var_x��var_y����סÿ��������x�����y����ĸı�ֵ����������ṩ�ķ����ĺ�������QUEEN���ơ�Ϊ��ʡƪ����������ǽ���Ľ��桢ʵ�ּ���ʾ������ͬһ�ļ���

///////////////////////////////////////////////////////////////////////
������������ʿ��������ĳ��� 

// �ļ���KNIGHT.CPP 
// ���ܣ�ʹ�û����㷨�����ʿ��������
#include <iostream.h> 
#include <iomanip.h> 
enum BOOLEAN { 
TRUE = 1, 
FALSE = 0 
}; 
const int MAX_WIDTH = 30; 
const int MAX_DIR = 8; 
class KNIGHT { 
public: 
// FUNCTION: ���ó�ʼ״̬ 
KNIGHT(int width); 
// FUNCTION: �ñȽ�ֱ�۵ķ�ʽ��ӡ����Ľ� 
// REQUIRE: �����ȵ����˳�Ա����tourist() 
void print(); 
// FUCTION: ���������ʼλ��(start_x, start_y)ʹ�û����㷨����ʿ���������һ���� 
// REQUIRE: (start_x, start_y)�����������õ����̿�ȷ�Χ�� 
BOOLEAN tourist(int start_x, int start_y); 
protected: 
// FUNCTION: ��ʼ����¼��ѡ��������飬��ÿ��ֵ��ΪMAX_DIR 
void init_direction(); 
// FUNCTION: ��ʼ����¼���ڵڼ�����λÿ��λ�õ����飬��ÿ��ֵ��Ϊ0 
void init_chessboard(); 
// FUNCTION: ���ó�ʼ״̬��������ʼ������������������飬��������ĳ�ʼλ�� 
void set_start(int x, int y); 
// FUNCTION: �ڵ�ǰλ��ѡ��һ���������ƽ�����һλ�� 
// RETURN: �����ѡ��һ�������ƽ��򷵻�TRUE�����򷵻�FALSE 
// NOTE: ���ú�������Ϊ�麯�����Ա�������������������ض���ú�����������̬�� 
virtual BOOLEAN select_direction(); 
// FUNCTION: �ӵ�ǰλ�û��ݵ���һλ�� 
// NOTE: ���ú�������Ϊ�麯�����Ա�������������������ض���ú�����������̬�� 
virtual void backward(); 
// FUNCTION: �ӵ�ǰλ���ƽ�����һλ�� 
// NOTE: ���ú�������Ϊ�麯�����Ա�������������������ض���ú�����������̬�� 
virtual void forward(); 
// FUNCTION: �ж����Ƿ��ܹ�����λ��(x, y)�� 
// RETURN: ������Ѿ�������λ�ã����λ�ó������̷�Χ����FALSE�����򷵻�TRUE 
BOOLEAN is_legal(int x, int y); 
// FUNCTION: �ж��Ƿ���ݵ���ʼ״̬ 
// RETURN: ��������ص���1�����ʾ�ص���ʼ״̬������TRUE�����򷵻�FALSE 
BOOLEAN back_to_start(); 
// FUNCTION: �ж��Ƿ�����������λ�� 
// RETURN: ��������������̸��������ʾ����������λ�ö�����TRUE�����򷵻�FALSE 
BOOLEAN is_end(); 
// ������������������סѡ��ĳ��������ƽ�����һλ��ʱx�����y�����ֵ�ı仯 
int var_x[MAX_DIR]; 
int var_y[MAX_DIR]; 
// ��¼��ڼ�������ĳ��λ�õ��������� 
int chessboard[MAX_WIDTH][MAX_WIDTH]; 
// ��¼����ĳ��λ��������һλ��ѡ��ڼ������򵽴�� 
int direction[MAX_WIDTH][MAX_WIDTH]; 
int width; // ���̿�� 
int curr_x, curr_y; // ��ĵ�ǰλ�� 
int step; // �Ѿ������Ĳ��� 
int last_direct
ion; // ��һλ�õ���ǰλ����ѡ�ķ��� 
}; 
KNIGHT::KNIGHT(int width) 
{ 
this->width = width; 
init_direction(); 
total_step = 0; 
} 
void KNIGHT::print() 
{ 
int x, y; 
cout << " +"; 
for (x = 0; x < width; x = x + 1) cout << "----+"; 
cout << '\n'; 
for (x = 0; x < width; x = x + 1) { 
cout << " |"; 
for (y = 0; y < width; y = y + 1) cout << setw(3) << chessboard[x][y] << " |"; 
cout << '\n'; 
cout << " +"; 
for (y = 0; y < width; y = y + 1) cout << "----+"; 
cout << '\n'; 
} 
} 
BOOLEAN KNIGHT::is_legal(int x, int y) 
{ 
if (x < 0 || x >= width) return FALSE; 
if (y < 0 || y >= width) return FALSE; 
if (chessboard[x][y] > 0) return FALSE; 
return TRUE; 
} 
BOOLEAN KNIGHT::back_to_start() 
{ 
if (step == 1) return TRUE; 
else return FALSE; 
} 
BOOLEAN KNIGHT::is_end() 
{ 
if (step > width * width) return TRUE; 
else return FALSE; 
} 
void KNIGHT::set_start(int x, int y) 
{ 
curr_x = x; curr_y = y; step = 1; 
chessboard[x][y] = step; step = step + 1; 
direction[x][y] = MAX_DIR; 
last_direction = MAX_DIR; 
} 
BOOLEAN KNIGHT::select_direction() 
{ 
int try_x, try_y; 
// last_directionΪMAX_DIR��ʾ��ǰλ����һ���µ�λ�ã������ƽ���ĳ��λ��(curr_x, curr_y)ʱ�� 
// direction[curr_x][curr_y]���¼��һλ�õ�(curr_x, curr_y)ʱ��ѡ��ķ�����ʱ 
// last_direction��ΪMAX_DIR������Ǹ�λ�������ƽ���λ�á� 
if (last_direction == MAX_DIR) last_direction = 0; 
else last_direction = last_direction + 1; 
while (last_direction < MAX_DIR) { 
// ����һ���ƽ����ĸ�λ���ǺϷ��ģ�����Ϸ���ѡ��÷��� 
try_x = curr_x + var_x[last_direction]; 
try_y = curr_y + var_y[last_direction]; 
if (is_legal(try_x, try_y)) break; 
last_direction = last_direction + 1; 
} 
if (last_direction == MAX_DIR) return FALSE; 
else return TRUE; 
} 
void KNIGHT::backward() 
{ 
step = step - 1; 
chessboard[curr_x][curr_y] = 0; 
// ��last_direction��Ϊ��һλ�õ�(curr_x, curr_y)��ѡ��ķ��� 
last_direction = direction[curr_x][curr_y]; 
// �������������ݵ���һλ�ã�ͬʱ���ݵ���һλ��֮������һλ������̽ʱӦ�ô� 
// last_direction+1�ķ���ʼ���ο���Ա����select_direction()�� 
curr_x = curr_x - var_x[last_direction]; 
curr_y = curr_y - var_y[last_direction]; 
} 
void KNIGHT::forward() 
{ 
// ���ƽ�ʱlast_direction�ǵ�ǰλ����ѡ��ķ��� 
curr_x = curr_x + var_x[last_direction]; 
curr_y = curr_y + var_y[last_direction]; 
chessboard[curr_x][curr_y] = step; 
step = step + 1; 
// ������򱻼�¼��һλ��(��ʱ�Ѿ�Ϊ(curr_x, curr_y))��direction�����С� 
direction[curr_x][curr_y] = last_direction; 
// last_direction��ֵ�Ѿ�����¼����ʱ��ΪMAX_DIR��ʾ��ǰλ��Ϊ���ƽ���λ�� 
last_direction = MAX_DIR; 
} 
BOOLEAN KNIGHT::tourist(int start_x, int start_y) 
{ 
init_chessboard(); 
set_start(start_x, start_y); 
do { 
if (select_direction()) forward(); 
else backward(); 
} while (!back_to_start() && !is_end()); 
if (back_to_start()) return FALSE; 
else return TRUE; 
} 
void KNIGHT::init_direction() 
{ 
var_x[0] = 2; var_y[0] = 1; 
var_x[1] = 1; var_y[1] = 2; 
var_x[2] = -1; var_y[2] = 2; 
var_x[3] = -2; var_y[3] = 1; 
var_x[4] = -2; var_y[4] = -1; 
var_x[5] = -1; var_y[5] = -2; 
var_x[6] = 1; var_y[6] = -2; 
var_x[7] = 2; var_y[7] = -1; 
} 
void KNIGHT::init_chessboard() 
{ 
int x, y, dir; 
for (x = 0; x < width; x = x + 1) { 
for (y = 0; y < width; y = y + 1) { 
chessboard[x][y] = 0; 
} 
} 
} 
int main() 
{ 
int width = 8; 
KNIGHT knight(width); 
int start_x, start_y; 
cout << "\nProgram begin...\n"; 
start_x = 4; start_y = 4; 
if (knight.tourist(start_x, start_y)) { 
knight.print(); 
}else { 
cout << "\nHave not found the solution for: "; 
cout << "Start: <" << start_x << ", " << start_y << ">, "; 
cout << "Width: " << width << "\n"; 
} 
return 1; 
} 

l ��ʿ��������Ŀ��ٽ�
���������ʿ��������ĳ���Ч�ʱȽϵͣ�����8��8�����̽������൱��һ��ʱ�䡣Ϊ�����ǿ�����ѡ��ǰ���Ŀ���·��ʱ����һЩ����ʽ����ʹ�����ѡ���ĳ����������˵�ǱȽϺõģ��Ӷ���������������̡� 
������ʿ��������һ������ʽ�����ǣ���ѡ��ǰ���ķ���ʱȥѡ���������������ķ��򣬵�����������ƽ�����һλ��ʱ�����λ����������ѡ��ķ������١�Ҳ����˵�ڵ�ǰλ������ѡһ����������?quot;����"�ķ������ƽ���������������ʽ����֮�󣬴����е�Ч�����������Ĺ����м��������ݡ� 
Ϊ��ʹ���������ʽ������������Ҫ�޸�����ĳ�Ա����select_direction()����ʱ��ÿ��λ��ѡ����ʱ�����ǰ���һ����˳����ѡ��Ϊ�˱����ڻ���ʱ�ظ�ѡ���򣬱����ס��ĳ��λ����Щ�����Ѿ�ѡ����ˣ�����ʹ����ά����cannot����ס������飬����ֵΪTRUEʱ��ʾĳ��λ�õ�ĳ�������Ѿ���̽���ˣ�ΪFALSE��ʾû����̽�������ӵ�ǰλ�û��ݵ���һλ���ǣ�Ҫ�Ȱѵ�ǰλ�����з����cannotֵ��ΪFALSE����Ϊ��һ���ٵ������λ��ʱ���з�����Ҫ������̽�� 
Ϊ���о���������ʽ�����Ч����Ҫ�������治ʹ������ʽ����ĳ����������Ǵ�KNIGHT��������һ����FAST_KNIGHT��֧�ֿ��������ʿ�������⡣�����������������cannot������ֻ��Ҫ���¶���select_direction(), backward()��forward()�Ϳ����ˡ���Ҫ���¶���backward()��forward()����Ϊ����������Ա��������Ҫά������cannot��ֵ��������Ա�����������κε��޸ġ�������KNIGHT�����Ѿ����⼸����Ա��������Ϊ�麯�����Ա��ڳ�Ա����tourist()�ж�̬��ѡ����Щ���������á�������Ҫѧϰ��ڰ��¶�̬��֮����ܳ����⶯̬�󶨵ĺ��塣 
����������У�����ֻ������FAST_KNIGHT�Ķ��壬���ߺ������޸���ʾ������ʹ����FAST_KNIGHT�������ʿ�������⡣ 

�����������������ʿ��������ĳ��� 

// �ļ���FASTKNIGHT.CPP 
// ���ܣ�ʹ�û����㷨���������ʿ�������� 
class FAST_KNIGHT: public KNIGHT { 
public: 
FAST_KNIGHT(int width); 
protected: 
// FUNCTION: ��ʼ��cannot���� 
void init_cannot(); 
// FUNCTION: �ڵ�ǰλ�ø�������ʽ����ѡ��һ���������ƽ�����һλ�� 
// RETURN: �����ѡ��һ�������ƽ��򷵻�TRUE�����򷵻�FALSE 
// NOTE: �ض���KNIGHT���select_direction() 
virtual BOOLEAN select_direction(); 
// FUNCTION: �ӵ�ǰλ�û��ݵ���һλ�ã�ע��ά��cannot���� 
// NOTE: �ض���KNIGHT���backward() 
virtual void backward(); 
// FUNCTION: �ӵ�ǰλ�ø�����ѡ��ķ����ƽ�����һλ�� 
// NOTE: �ض���KNIGHT���forward() 
virtual void forward(); 
// ������סĳ��λ��ĳ�������Ƿ��Ѿ���̽�� 
BOOLEAN cannot[MAX_WIDTH][MAX_WIDTH][MAX_DIR]; 
}; 
FAST_KNIGHT::FAST_KNIGHT(int width): KNIGHT(width) 
{ 
init_cannot(); 
} 
void FAST_KNIGHT::init_cannot() 
{ 
int x, y, dir; 
for (x = 0; x < width; x = x + 1) 
for (y = 0; y < width; y = y + 1) 
for (dir = 0; dir < width; dir = dir + 1) cannot[x][y][dir] = FALSE; 
} 
BOOLEAN FAST_KNIGHT::select_direction() 
{ 
int try_x, try_y, next_x, next_y; 
int dir_index, next_index; 
int min_dir, count; 
min_dir = MAX_DIR; last_direction = MAX_DIR; 
for (dir_index = 0; dir_index < MAX_DIR; dir_index = dir_index + 1) { 
// ѡ��һ������ʹ�ø��ݸ÷����ƽ�����һλ��ʱ���ڸ�λ�ÿ�ѡ�ķ������� 
try_x = curr_x + var_x[dir_index]; 
try_y = curr_y + var_y[dir_index]; 
if (is_legal(try_x, try_y) && !cannot[curr_x][curr_y][dir_index]) { 
// ���λ����Ϊ��һλ���ǺϷ�����ô�����λ�ÿ�ѡ�ķ��� 
count = 0; 
for (next_index = 0; next_index < MAX_DIR; next_index++) { 
next_x = try_x + var_x[next_index]; 
next_y = try_y + var_y[next_index]; 
if (is_legal(next_x, next_y)) count = count + 1; 
} 
if (count < min_dir) { 
// ��¼�������ٿ�ѡ�������һλ�� 
last_direction = dir_index; 
min_dir = count; 
} 
} 
} 
if (last_direction == MAX_DIR) return FALSE; 
else return TRUE; 
} 
void FAST_KNIGHT::backward() 
{ 
int dir; 
step = step - 1; 
chessboard[curr_x][curr_y] = 0; 
// ��λ��(curr_x, curr_y)���ݣ���ô��һ���ٵ����λ��ʱ���з�����Ҫ������̽ 
for (dir = 0; dir < MAX_DIR; dir = dir + 1) cannot[curr_x][curr_y][dir] = FALSE; 
last_direction = direction[curr_x][curr_y]; 
curr_x = curr_x - var_x[last_direction]; 
curr_y = curr_y - var_y[last_direction]; 
} 
void FAST_KNIGHT::forward() 
{ 
// ��λ�õ���������Ѿ���̽���� 
cannot[curr_x][curr_y][last_direction] = TRUE; 
curr_x = curr_x + var_x[last_direction]; 
curr_y = curr_y + var_y[last_direction]; 
chessboard[curr_x][curr_y] = step; 
step = step + 1; 
direction[curr_x][curr_y] = last_direction; 
last_direction = MAX_DIR; 
} 

l ˼������� 
�ڳ�����������������֮�󣬶��߿ɽ�һ��˼���������⣺ 
1.�������˻ʺ�����ĳ���������board���Ǳ���ģ���Ϊ����solution������ȫ������ĸ�λ���лʺ��޸���������ʹ�ò���Ҫ����board�������˻ʺ���������н⡣ 
2.˼�����������ʿ���������е�����ʽ����Ϊʲô�ܹ�ʹ�����������м��������ݡ���һ����ȸ�����ʽ���򣬿�������˻ʺ������һ����ʱ����������������ʽ�����Լ��������̡� 
3.ʹ�û����㷨����Թ����⣬�Լ������Թ�����Ľ�һ���������������Ҫ�����ݽṹ����ϸ�����������㷨�� 
4.����������������ʿ��������ĳ������������㷨ʱ���Զ����Ϸֽ⡢���󾫵�˼�룬��һ�����ʹ���������������˼�룬�ر������ö�̬�󶨵ĺô���
