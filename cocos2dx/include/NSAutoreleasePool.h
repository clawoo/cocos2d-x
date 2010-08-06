/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __NS_AUTO_RELEASE_POOL_H__
#define __NS_AUTO_RELEASE_POOL_H__

#include "NSObject.h"
#include "NSMutablearray.h"

#include <stack>
namespace   cocos2d {

class NSAutoreleasePool
{
public:
	NSAutoreleasePool(void);
	~NSAutoreleasePool(void);

	void addObject(NSObject *pObject);
	void removeObject(NSObject *pObject);

	void clear(void);
private:
	NSMutableArray<NSObject*> *m_pManagedObjectArray;
};

class NSPoolManager
{
public:
    ~NSPoolManager();

	void finalize(void);
    void push(void);
	void pop(void);

	void removeObject(NSObject *pObject);
	void addObject(NSObject *pObject);

public:
	static NSPoolManager* getInstance();

private:
	NSPoolManager();
	NSAutoreleasePool* getCurReleasePool();

private:
	static NSPoolManager *m_pPoolManager;

private:
	std::stack<NSAutoreleasePool *> *m_pReleasePoolStack;
	NSAutoreleasePool *m_pCurReleasePool;
};
}//namespace   cocos2d 

#endif //__NS_AUTO_RELEASE_POOL_H__