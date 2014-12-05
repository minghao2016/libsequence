#define BOOST_TEST_MODULE fastqIO
#define BOOST_TEST_DYN_LINK 

#include <Sequence/fastq.hpp>
#include <Sequence/SeqExceptions.hpp>
#include <fstream>
#include <boost/test/unit_test.hpp>
#include <unistd.h>
#include <iterator>
#include <iostream>

BOOST_AUTO_TEST_CASE( input_test )
{
  std::ifstream in("data/data.fastq");
  if (!in)
    {
      std::cerr << "Error, couldn't find input file!\n";
      exit(1);
    }
  Sequence::fastq f;

  unsigned count = 0;
  BOOST_REQUIRE_NO_THROW 
    (
     while(!in.eof())
       {
	 in >> f >> std::ws;
	 ++count;
       }
     );
  BOOST_CHECK_EQUAL(count,50);
}

BOOST_AUTO_TEST_CASE( input_test2 )
{
  std::ifstream in("data/data.fastq");
  if (!in)
    {
      std::cerr << "Error, couldn't find input file!\n";
      exit(1);
    }
  Sequence::fastq f;

  unsigned count = 0;
  BOOST_REQUIRE_NO_THROW 
  (
     unsigned count = 0;
     std::istream_iterator<Sequence::fastq> i(in);
     for( ; i != std::istream_iterator<Sequence::fastq>() ; ++i )
       {
	 ++count;  
       }
     BOOST_CHECK_EQUAL(count,50);
   ); 
}