//
// DataTest.h
//
// $Id: //poco/Main/Data/testsuite/src/DataTest.h#6 $
//
// Definition of the DataTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef DataTest_INCLUDED
#define DataTest_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/BinaryReader.h"
#include "Poco/BinaryWriter.h"
#include "Poco/Data/Row.h"
#include "CppUnit/TestCase.h"


class DataTest: public CppUnit::TestCase
{
public:
	DataTest(const std::string& name);
	~DataTest();

	void testSession();
	void testStatementFormatting();
	void testFeatures();
	void testProperties();
	void testLOB();
	void testCLOB();
	void testCLOBStreams();
	void testColumnVector();
	void testColumnVectorBool();
	void testColumnDeque();
	void testColumnList();
	void testRow();
	void testRowSort();
	void testRowFormat();
	void testDateAndTime();
	void testExternalBindingAndExtraction();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
	void testRowStrictWeak(const Poco::Data::Row& row1, 
		const Poco::Data::Row& row2, 
		const Poco::Data::Row& row3);
		/// Strict weak ordering requirement for sorted containers
		/// as described in Josuttis "The Standard C++ Library"
		/// chapter 6.5. pg. 176.
		/// For this to pass, the following condition must be satisifed: 
		/// row1 < row2 < row3

	void writeToCLOB(Poco::BinaryWriter& writer);
	void readFromCLOB(Poco::BinaryReader& reader);
};


#endif // DataTest_INCLUDED