ժ��: ���ڡ���֧����ʮ���޼��㹫ʽ ��ӡ��ҳ �رձ����� 
1. �����ڹ�ʽ
����=[5+A(ʵ������)] mod 7

2. ��֧���㹫ʽ
��ʮ���Ӹ�֧��ţ���1->59->0��
��ʮ���Ӹ�֧���=[23+A(ʵ������)] mod 60

3. ��ʮ���޼��㹫ʽ
��ʮ�������=[23+A(ʵ������)] mod 28

4. ʵ������A�ļ���
A=B(��������)+C(��������)
B=(������-1)*365+(Ҫ���㵽�����������)
����1984��2��1�յĻ�������B=(1984-1)*365+(31+1)=723827(��)��
���У�31��1��Ϊ31�죬1Ϊ2��1��Ϊ1�졣
��Ԫ308��8��28�յĻ�������
B=(308-1)*365+(31+28+31+30+31+30+31+27)=112055+239=112294(��)
�����(Ҫ���㵽�����������)���õ��ǹ��������������Ĺ����Һ�
��Сѧ��ѧ���ˡ���������

C=(������-1) div 4 -�������ֵ + fixValue2
fixValue2Ϊ0����1����ֵΪ0��������Ϊ����(�������귨)֮�е�3��
1��֮���Ϊ1��

�������ֵ���㣺
��ԪԪ��1��1����1582��10��14��Ϊ0��
1582��10��15����1699��12��31��Ϊ10��
��1701��1��1����ÿ����һ�������ۼ�1�����ܱ�400���������Ͳ���
��1���˷������㼴�ɡ�
--��һ�����⣬1700����һ�������ֵӦΪ�����أ��㷨������û��
������������Ӧ����10��

��1701��1��1�������ֵΪ11����1801��1��1�����������ֵΪ12��
��1901��1��1�����������ֵΪ13��
��2001���������ֵ��Ϊ13����Ϊ2000���ܱ�400�������ʲ��ۼӡ���
2101��1��1�����������ֵΪ14��

5. ʵ����1998.3.15�����ڡ���֧���ʮ����
B=(1998-1)*365+(31+28+15)=728979
C=(1998-1) div 4 - 13 + 0 = 486
A=B+C=728979+486=729465
�������=(5+729465) mod 7=0����Ϊ������
��֧���=(13+729465) mod 60=58����Ϊ����
��ʮ�������=(23+729465) mod 28=4����Ϊ��

===================================================
�ÿ��£�����һЩ������ʽ������������Щ������֪����ô�õ���

��ʮ�Ľڽ������㷨��
����֪��Ľ���ʱ������22��Сʱ35�֣�����24Ҫ��ȥ24��������60
��1��Сʱ�����õ�8���ĸ��ڽ���ʱ����
��2000����ˮ����ʱ��Ϊ16ʱ22�֣���2008����ˮ����ʱ��Ϊ14ʱ52
�֡�
��Ϊ16ʱ22��+22ʱ35��=38ʱ57�֡�38-24=14ʱ��
˭֪����ԪԪ�굽��Ԫ����Ľ����գ�����㷨�Ϳ���ʵ���ˡ�--��
�����㷨���Խ��������⡣˭���ԣ�

ũ�������㷨��
ũ���У���ʮ�Ľ���(ʮ��������ʮ������)������������ĩ�Ļ�����
���¾�û��������ũ���������н�(����)����(����)���·ݹ涨Ϊ��
�¡�ƽ�����㣬19�����߸����¡�
����ʮ�ĸ�������ʮ��������ʮ����������ô�ֵ��أ���û�����ϣ�
����Ӧ����һ����һ�����������档 :(

unit CNYear; 

interface 
uses sysutils; 
type TCNDate = Cardinal; 
function DecodeGregToCNDate(dtGreg:TDateTime):TCNDate; 
function 
GetGregDateFromCN(cnYear,cnMonth,cnDay:word;bLeap:Boolean=Fal
se):TDateTime; 
function GregDateToCNStr(dtGreg:TDateTime):String; 
function isCNLeap(cnDate:TCNDate):boolean; 
implementation 
const cstDateOrg:Integer=32900; //����1990-01-27��TDateTime��
ʾ ��Ӧũ��1990-01-01 
const cstCNYearOrg=1990; 
const cstCNTable:array[cstCNYearOrg..cstCNYearOrg + 60] of 
WORD=( // unsigned 16-bit 
24402, 3730, 3366, 13614, 2647, 35542, 858, 1749, //1997 
23401, 1865, 1683, 19099, 1323, 2651, 10926, 1386, //2005 
32213, 2980, 2889, 23891, 2709, 1325, 17757, 2741, //2013 
39850, 1490, 3493, 61098, 3402, 3221, 19102, 1366, //2021 
2773, 10970, 1746, 26469, 1829, 1611, 22103, 3243, //2029 
1370, 13678, 2902, 48978, 2898, 2853, 60715, 2635, //2037 
1195, 21179, 1453, 2922, 11690, 3474, 32421, 3365, //2045 
2645, 55901, 1206, 1461, 14038); //2050 
//�������� 
// 0101 111101010010 ����λ������λ��,��12λ��ʾ��С��,����30
��,С��29��, 
//����һ����С��,��������������2017/06,2036/06,2047/05 
//�������������λ������λ�ñ�ʾ���е����Ϊ����Ϊ1 ���⴦��
��wLeapNormal���� 
// //2017/06 28330->61098 2036/06 27947->60715 2047/05 
23133->55901 

//���ϣ���û��,������һ����Ϣ:ũ�������ͺ���2����. 
//������ת��Ϊũ�� 
//����:12λ���+4λ�·�+5λ���� 
function DecodeGregToCNDate(dtGreg:TDateTime):TCNDate; 
var 
iDayLeave:Integer; 
wYear,wMonth,wDay:WORD; 
i,j:integer; 
wBigSmallDist,wLeap,wCount,wLeapShift:WORD; 
label OK; 
begin 
result := 0; 
iDayLeave := Trunc(dtGreg) - cstDateOrg; 
DecodeDate(IncMonth(dtGreg,-1),wYear,wMonth,wDay); 
if (iDayLeave < 0) or (iDayLeave > 22295 )then Exit; 
//Raise Exception.Create('Ŀǰֻ����1990-01-27�Ժ��'); 
//Raise Exception.Create('Ŀǰֻ����2051-02-11��ǰ��'); 
for i:=Low(cstCNTable) to High(cstCNTable) do begin 
wBigSmallDist := cstCNTable[i]; 
wLeap := wBigSmallDist shr 12; 
if wLeap > 12 then begin 
wLeap := wLeap and 7; 
wLeapShift := 1; 
end else 
wLeapShift := 0; 
for j:=1 to 12 do begin 
wCount:=(wBigSmallDist and 1) + 29; 
if j=wLeap then wCount := wCount - wLeapShift; 
if iDayLeave < wCount then begin 
Result := (i shl 9) + (j shl 5) + iDayLeave + 1; 
Exit; 
end; 
iDayLeave := iDayLeave - wCount; 
if j=wLeap then begin 
wCount:=29 + wLeapShift; 
if iDayLeave < wCount then begin 
Result := (i shl 9) + (j shl 5) + iDayLeave + 1 + (1 shl 21); 
Exit; 
end; 
iDayLeave := iDayLeave - wCount; 
end; 
wBigSmallDist := wBigSmallDist shr 1; 
end; 
end; 
//����ֵ: 
// 1λ���±�־ + 12λ���+4λ�·�+5λ���� (��22λ) 
end; 
function isCNLeap(cnDate:TCNDate):boolean; 
begin 
result := (cnDate and $200000) <> 0; 
end; 
function 
GetGregDateFromCN(cnYear,cnMonth,cnDay:word;bLeap:Boolean=Fal
se):TDateTime; 
var 
i,j:integer; 
DayCount:integer; 
wBigSmallDist,wLeap,wLeapShift:WORD; 
begin 
// 0101 010010101111 ����λ������λ��,��12λ��ʾ��С��,����30
��,С��29��, 
DayCount := 0; 
if (cnYear < 1990) or (cnYear >2050) then begin 
Result := 0; 
Exit; 
end; 
for i:= cstCNYearOrg to cnYear-1 do begin 
wBigSmallDist := cstCNTable[i]; 
if (wBIgSmallDist and $F000) <> 0 then DayCount := DayCount + 
29; 
DayCount := DayCount + 12 * 29; 
for j:= 1 to 12 do begin 
DayCount := DayCount + wBigSmallDist and 1; 
wBigSmallDist := wBigSmallDist shr 1; 
end; 
end; 
wBigSmallDist := cstCNTable[cnYear]; 
wLeap := wBigSmallDist shr 12; 
if wLeap > 12 then begin 
wLeap := wLeap and 7; 
wLeapShift := 1; //����������. 
end else 
wLeapShift := 0; 
for j:= 1 to cnMonth-1 do begin 
DayCount:=DayCount + (wBigSmallDist and 1) + 29; 
if j=wLeap then DayCount := DayCount + 29; 
wBigSmallDist := wBigSmallDist shr 1; 
end; 
if bLeap and (cnMonth = wLeap) then //��Ҫ���µ���? 
DayCount := DayCount + 30 - wLeapShift; 
result := cstDateOrg + DayCount + cnDay - 1; 
end; 

//��������ʾ��ũ���ַ���. 
function GregDateToCNStr(dtGreg:TDateTime):String; 
const hzNumber:array[0..10] of string=('��','һ','��','��','
��','��','��','��','��','��','ʮ'); 
function ConvertYMD(Number:Word;YMD:Word):string; 
var 
wTmp:word; 
begin 
result := ''; 
if YMD = 1 then begin //��� 
while Number > 0 do begin 
result := hzNumber[Number Mod 10] + result; 
Number := Number DIV 10; 
end; 
Exit; 
end; 
if Number<=10 then begin //��ֻ��1λ 
if YMD = 2 then //�·� 
result := hzNumber[Number] 
else //�� 
result := '��' + hzNumber[Number]; 
Exit; 
end; 
wTmp := Number Mod 10; //��λ 
if wTmp <> 0 then result := hzNumber[wTmp]; 
wTmp := Number Div 10; //ʮλ 
result:='ʮ'+result; 
if wTmp > 1 then result := hzNumber[wTmp] + result; 
end; 
var 
cnYear,cnMonth,cnDay:word; 
cnDate:TCNDate; 
strLeap:string; 
begin 
cnDate:= DecodeGregToCNDate(dtGreg); 
if cnDate = 0 then begin 
result := '����Խ��'; 
Exit; 
end; 
cnDay := cnDate and $1F; 
cnMonth := (cnDate shr 5) and $F; 
cnYear := (cnDate shr 9) and $FFF; 
//���Ե�22λ,Ϊ1��ʾ���� 
if isCNLeap(cnDate) then strLeap:='(��)' else strLeap := ''; 
result := 'ũ��' + ConvertYMD(cnYear,1) + '��' + 
ConvertYMD(cnMonth,2) + '��' 
+ strLeap + ConvertYMD(cnDay,3) ; 
end; 
end.   