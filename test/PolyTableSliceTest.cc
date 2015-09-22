//! \file PolyTableSliceTest.cc @brief Tests for Sequence/PolyTableSlice.hpp
#define BOOST_TEST_MODULE ComparisonsTest
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <Sequence/SimData.hpp>
#include <Sequence/PolyTableSlice.hpp>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
using namespace std;
using namespace Sequence;

BOOST_AUTO_TEST_CASE( lastwindows1 )
{
  vector<pair<double,string> > data;
  for(double i = 0.05 ; i < 0.9 ; i += 0.1 )
    data.push_back(make_pair(i,string("001000")));
  SimData d(data.begin(),data.end());
  PolyTableSlice<SimData> w(d.sbegin(),d.send(),0.1,0.1);
  BOOST_REQUIRE_EQUAL(w.size(),10);
}