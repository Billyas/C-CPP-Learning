# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define ElemType char

typedef struct dlistnode {
	ElemType data;
	struct dlistnode *pre;
	struct dlistnode *next;
}DLinkNode;

void CreatList(DLinkNode*& L, ElemType* a, int n)  //婵犮垼鍩栭幐鎶藉极閹剧粯瀵犲璺侯儑閵嗗﹪姊虹捄銊ユ瀾闁哄顭烽獮蹇涙倻閼恒儲娅㈤梺鍝勫€堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅锟�
{
	DLinkNode* s;
	int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL, L->pre = NULL;


	for (i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;        //闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘辩暉闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘愁潐缁嬪鍩€椤掑嫭鐓ラ柣鏂挎啞閻忣噣鏌熷畡鏉挎Щ闁告ɑ鎹囬弻銊╂偄缁嬭法鍔电紒鐐緲椤︽壆鈧艾缍婇弻銊╂偄閸涘﹦浼勯梺褰掝棑閸忔﹢寮幘璇叉闁靛牆妫楅锟�
		if (L->next != NULL) {
			L->next->pre = s;
		}
		L->next = s;             //闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘辩暉闂備浇娉曢崰鎰板几婵犳艾绠紒瀣靛墴閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌鏋戦柡瀣煼楠炲繘鏁撻敓锟�
		s->pre = L;
	}
}

void CreatListTail(DLinkNode*& L, ElemType* a, int n)
{
	int i;
	DLinkNode* s, * r ;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;

	for (i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];

		r->next = s;
		s->pre = r;

		r = s;
	}

	r ->next= NULL;
	
}

bool InsertList(DLinkNode*& L, int i, ElemType e)
{
	int j = 0;
	DLinkNode* s, * p = L;

	while (j<i-1 && p != NULL) {
		j++;
		p = p->next;
	}

	if (p == NULL)  
		return false;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		
		s->next = p->next;
		if (p->next != NULL) {
			p->next->pre = s;
		}

		s->pre = p;
		p->next = s;
		return true;
	}

}

bool ListDelet(DLinkNode*&L,int i,ElemType& e)
{
	int j = 0;
	DLinkNode* p = L,*q;

	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	q = p;
	if (p == NULL)
		return false;
	else /*{
		p->next = p->next->next;
		p->next->pre = p;
		free(q->next);
	}*/
	{	   q = p->next;		//q闂佸湱枪濞差參寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌鏋旂紒鍌涘浮閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌娅愰柟鍑ゆ嫹
	if (q == NULL)	   	//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘缁樺殟闁稿本绮犻弳婊堟煙妞嬪簶鎵涢梻浣芥硶閸犳劙寮告繝姘闁绘垼濮ら弲鎼佹煛閸屾ê鈧牜鈧艾缍婇弻銊╂偄閾忕懓鎽甸梺瑙勫絻椤戝棛鈧艾缍婇弻銊╂偄閸涘﹦浼勯梺褰掝棑閸忔﹢寮幘璺虹筏婵犳洘顒e
		return false;
	e = q->data;//闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌￠崒妯衡偓鏍偓姘秺瀹曟岸鎮╃紒妯绘闂佸搫鍊堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佺懓鍢查崲鏌ュ焵椤掑﹥瀚�
	p->next = q->next;		//闂備浇娉曢崰鎰板几婵犳艾绠€瑰嫭婢橀拑鐔兼⒑鐠恒劌鏋戦柡瀣煼楠炲繘鎮滈懞銉︽闂佸搫鍊堕崐鏍偓姘秺閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟煕閹烘柨鈻堥柡浣规崌瀵剟濡堕崱妤婁紦q闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌ㄩ悤鍌涘
	if (q->next != NULL)    	//闂備浇娉曢崰鎰板几婵犳艾绠紒灞剧洴閺屻劑鎮㈤崨濠勪紕闂佸綊顥撻崗姗€寮幘璇叉闁靛牆妫楅鍫曟⒑鐠恒劌鏋欏┑鈽嗗弮閹喚鈧稒锚椤忓爼鏌熼幁鎺戠伈闁轰焦鎹囧顒勫Χ閸℃浼�
		q->next->pre = p;	//闂備浇娉曢崰鎾愁焽妤ｅ啯顥堥柍鍝勫€搁绉栭梻浣芥硶閸犳劙寮告繝姘闁绘垼濮ら弲鎼佹煛閸屾ê鈧牜鈧艾缍婇獮鎺楀閵堝棙娅㈤梺鍝勫€堕崐鏍偓姘秺閺屻劑鎮㈠ú缁樺仴闁汇埄鍨奸崰妤冣偓姘秺閺屻劑鎮㈠ú缁樻櫗闂傚倸鐗冮弲婊呪偓姘秺閺屻劑鎮ら崒娑橆伓
	free(q);		   	//闂備浇娉曢崰鏍矗濞差亜绀勯柕鍫濇椤忕闂備浇娉曢崰鎰板几婵犳艾绠柣鎴ｅГ閺呮悂鏌ㄩ悤鍌涘
	return true;
	}

}

void DisPlay(DLinkNode* L)
{
	DLinkNode* p = L->next;
	while (p != NULL) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}



int main()
{
	ElemType a[12] = "hello world";
	int n = 12;
	char e = 'm';
	DLinkNode* L;
	CreatListTail(L, a, n);
	DisPlay(L);

	InsertList(L, 3, e);
	DisPlay(L);

	ListDelet(L, 7, e);
	DisPlay(L);

    system("pause");
	return 0;
}