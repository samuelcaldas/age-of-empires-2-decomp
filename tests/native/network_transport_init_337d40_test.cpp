#include <cassert>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <vector>
#include "network_transport_init_337d40.h"
int D_004E3560, D_004E3564, D_004E353C, D_004E3538, D_004E3534;
unsigned int D_004E3548[2], D_004E3540[2];
TransportAddress D_010890B0, D_010890C0, D_010890D0;
TransportThread D_010931A0;
char D_0108B1A0[32768], _gp;
extern "C" {
extern const char D_004D1F60[]="EUI64=%04x:%04x\n";
extern const char D_004D1F80[]="rx", D_004D1FC0[]="tx", D_004D2000[]="bc", D_004D2040[]="connect";
extern const char D_004D2090[]="start", D_004D20B0[]="thread";
void func_337B30() {}
}
static std::vector<int> calls;
static int failure, success_at, attempts[4], semas, sockets, logs;
static bool negative_resources;
static int resource(int n) { return negative_resources ? -n : n; }
extern "C" int func_104D20(TransportSema *s) {
 assert(s->max_count==1 && s->init_count==1 && s->option==0);
 calls.push_back(10); return resource(100 + ++semas);
}
extern "C" int func_389120(unsigned int *p) {
 assert(D_004E3560==resource(101) && D_004E3564==resource(102));
 calls.push_back(20); p[0]=0x12345678; p[1]=0x89abcdef; return -99;
}
extern "C" int func_388BA0(int a,int b,int c) {
 assert(a==60 && b==2 && c==0); calls.push_back(30); return resource(200 + ++sockets);
}
static int operation(int stage,int sd,const TransportAddress *a,int len) {
 assert(len==16 && sd==resource(201+(stage==3 ? 2 : stage)));
 assert(a==(stage==3 ? &D_010890D0 : &D_010890B0));
 assert(a->len==16 && a->family==60);
 assert(a->port==(stage==0 || stage==3 ? 0x3412 : 0));
 assert(a->node[0]==(stage==3 ? ~0u : 0u));
 assert(a->node[1]==(stage==3 ? ~0u : 0u));
 assert(D_010890C0.len==16 && D_010890C0.family==60 && D_010890C0.port==0x3412);
 assert(D_010890C0.node[0]==0xa5a5a5a5 && D_010890C0.node[1]==0xa5a5a5a5);
 assert(a->tail[0]==0xa5 && D_010890D0.tail[3]==0xa5);
 calls.push_back(40+stage); ++attempts[stage];
 return stage==failure && attempts[stage]<success_at ? -7 : 0;
}
extern "C" int func_388C20(int sd,const TransportAddress *a,int len) {
 int stage=sd==resource(201) ? 0 : sd==resource(202) ? 1 : 2;
 return operation(stage,sd,a,len);
}
extern "C" int func_388CC0(int sd,const TransportAddress *a,int len) { return operation(3,sd,a,len); }
extern "C" int func_104B20(TransportThread *t) {
 assert(t==&D_010931A0 && t->entry==func_337B30 && t->stack==D_0108B1A0);
 assert(t->stack_size==32768 && t->priority==11 && t->gp==&_gp);
 assert(t->status==int(0xa5a5a5a5)); calls.push_back(50); return failure==4 ? -1 : 0;
}
extern "C" int func_104B40(int id,void *arg) { assert(id==0 && arg==0); calls.push_back(60); return -42; }
extern "C" int func_118de0(const char *fmt,...) {
 va_list ap; va_start(ap,fmt);
 if(fmt==D_004D1F60) {
  unsigned int a=va_arg(ap,unsigned int),b=va_arg(ap,unsigned int);
  assert(a==(logs==0 ? 0x78563412u : 0x12345678u));
  assert(b==(logs==0 ? 0xefcdab89u : 0x89abcdefu));
  ++logs; calls.push_back(21);
 } else if(fmt==D_004D2090) calls.push_back(70);
 else if(fmt==D_004D20B0) { assert(va_arg(ap,int)==353); calls.push_back(71); }
 else {
  const char *formats[]={D_004D1F80,D_004D1FC0,D_004D2000,D_004D2040};
  int lines[]={320,328,334,340}; assert(fmt==formats[failure]);
  assert(va_arg(ap,int)==lines[failure]);
  assert(va_arg(ap,int)==(success_at==5 ? 0 : -7)); calls.push_back(80+failure);
 }
 va_end(ap);
 if(fmt==D_004D2090) return 71;
 if(fmt==D_004D20B0) return -33;
 return 1;
}
int main(int argc,char **argv) {
 failure=argc>1 ? std::atoi(argv[1]) : -1;
 success_at=argc>2 ? std::atoi(argv[2]) : 1;
 negative_resources=argc>3;
 std::memset(&D_010890B0,0xa5,sizeof(D_010890B0));
 std::memset(&D_010890C0,0xa5,sizeof(D_010890C0));
 std::memset(&D_010890D0,0xa5,sizeof(D_010890D0));
 std::memset(&D_010931A0,0xa5,sizeof(D_010931A0));
 int result=func_00337D40();
 std::vector<int> expected;
 expected.push_back(10); expected.push_back(10); expected.push_back(20);
 expected.push_back(21); expected.push_back(21);
 expected.push_back(30); expected.push_back(30); expected.push_back(30);
 for(int stage=0;stage<4;++stage) {
  int n=stage==failure ? (success_at>5 ? 5 : success_at) : 1;
  for(int i=0;i<n;++i) expected.push_back(40+stage);
  if(n==5) expected.push_back(80+stage);
 }
 expected.push_back(50);
 if(failure!=4) expected.push_back(60);
 expected.push_back(failure==4 ? 71 : 70);
 assert(calls==expected);
 assert(D_004E3540[0]==0x78563412 && D_004E3540[1]==0xefcdab89);
 assert(D_004E353C==resource(201) && D_004E3538==resource(202) && D_004E3534==resource(203));
 assert(result==(failure==4 ? -33 : 71));
 return 0;
}
