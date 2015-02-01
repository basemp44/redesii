#ifndef _IRCINTERNALS_H_
#define  _IRCINTERNALS_H_

inline __C__		(char *s, char *p, char *c);
inline __CP__		(char *s, char *p, char *c, char *p1);
inline __CO__		(char *s, char *p, char *c, char *o1);
inline __CM__		(char *s, char *p, char *c, char *m);
inline __CPP__		(char *s, char *p, char *c, char *p1, char *p2);
inline __CPM__		(char *s, char *p, char *c, char *p1, char *m);
inline __COO__		(char *s, char *p, char *c, char *o1, char *o2);
inline __CPO__		(char *s, char *p, char *c, char *p1, char *o);
inline __COP__		(char *s, char *p, char *c, char *o, char *p1);
inline __CPS__		(char *s, char *p, char *c, char *p1, char *m);
inline __CPPP__		(char *s, char *p, char *c, char *p1, char *p2, char *p3);
inline __CPPM__		(char *s, char *p, char *c, char *p1, char *p2, char *m);
inline __CPPO__		(char *s, char *p, char *c, char *p1, char *p2,char *o);
inline __CPOO__		(char *s, char *p, char *c, char *p1, char *o1, char *o2);
inline __CPOM__		(char *s, char *p, char *c, char *p1, char *o, char *m);
inline __CPPOM__	(char *s, char *p, char *c, char *p1, char *p2, char *o, char *m);
inline __CPPPP__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *p4);
inline __CPPPO__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *o1);
inline __CPPPM__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *m);
inline __CPOOOO__	(char *s, char *p, char *c, char *p1, char *o1, char *o2, char *o3, char *o4);
inline __CPPPPP__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *p4, char *p5);
inline __CPPPPPM__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *p4, char *p5, char *m);
inline __CPPPPPP__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *p4, char *p5, char *p6);
inline __CPPPPPNM__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *p4, char *p5, int n,    char *m);
inline __CPPPPPPM__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *m);
inline __CPPPPPPP__	(char *s, char *p, char *c, char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7);

#endif
