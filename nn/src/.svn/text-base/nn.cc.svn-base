#include <iostream>
#include <vector>
#include <getopt.h>
#include <string>
#include "batchbackprop.hh"
#include "backprop.hh"
#include "pswarm.hh"
#include "letter-recognition_driver.hh"
#include "neuron.hh"
#include "nn.hh"
#include "test_nn.hh"

#define PACKAGE "1"
#define VERSION "0.1"

char	*program_name;
int	g_debug = 0;
int	g_train = 0;
int	g_activate = 0;
int	g_test = 0;
int	g_output = 0;
char	*g_dataset_file = 0;
char	*g_correspondence_file = 0;
char	*g_ocr_file = 0;

enum option_e
  {
    opt_debug = 'd',
    opt_help = 'h',
    opt_version = 'v',
    opt_train = 't',
    opt_activate = 'a',
    opt_test = 'e',
    opt_output = 'o'
  };

static struct option const long_options[] =
  {
    {"help",	no_argument,		NULL,		opt_help},
    {"version",	no_argument,		NULL,		opt_version},
    {"debug",	no_argument,		&g_debug,	opt_debug},
    {"train",	required_argument,	&g_train,	opt_train},
    {"activate",	required_argument,	&g_activate,	opt_train},
    {"test",	required_argument,	&g_test,	opt_train},
    {"output",	required_argument,      &g_output,	opt_output},
    {NULL, 0, NULL, 0}
  };

static const char short_options[] = "dhvtaeo";

static void usage(void)
{
  std::cerr << "Usage: " << std::endl
	    << "\ttraining: " << program_name << " -t dataset_file corr_file"
	    << std::endl 
	    << "\ttest: " << program_name 
	    << "-t ocr_file dataset corr_file beginning end" 
	    << std::endl
	    << "\tactivation: " << program_name 
	    << "-a ocr_file dataset corr_file " 
	    << std::endl;

  std::cerr << "
Options:
  -h, --help		display this help and exit
  -v, --version		display the version and exit
  -d, --debug		display debug information during execution
  -t, --train dataset corr_file	nline
			train the neural network
			dataset: contain the data used to train the net
			corr_file: contain the output for each class
			nline: number of pattern used for training
  -o, --output ofile corr_file
			output the network on the file ofile. If the option
			is omitted, output on stdout
  -e, --test ocr_file dataset corr_file beginning end
			activate the network on a dataset and return stats
			dataset: contain the data used to train the net
			ocr_file: contain the network
			corr_file: contain the output for each class.
			beginning: first line where to begin
			end: last line where to end
  -a, --activate ocr_file dataset corr_file
			activate the network on a dataset and return stats
			dataset: contain the data used to train the net
			ocr_file: contain the network
			corr_file: contain the output for each class."
	    << std::endl;
  exit(0);
}

static void version(void)
{
  std::cout << program_name << " (" PACKAGE ") " VERSION << std::endl;
  std::cout << "written by Jean-Daniel Michaud (michau_j@epita.fr)" 
	    << std::endl;
  exit(0);
}

double sigmoide(double x)
{
  return (1.0 / (1.0 + exp(-0.5 * x)));
}

double sigmoide2(double x)
{
  return (1.0 / (1.0 + exp(-0.05 * x)));
}

double id(double x)
{
  return x;
}

int main(int argc, char **argv)
{
  program_name = argv[0];
  int	c;

  unsigned first_line = 0;
  unsigned last_line = 0;
  unsigned nline = 0;

  while ((c = getopt_long(argc, argv, 
			  short_options, long_options, NULL)) != -1)
    {
      switch (c)
	{
	case opt_help:
	  usage();
	case opt_version:
	  version();
	case opt_debug:
	  g_debug = true;
	case opt_train:
	  g_train = 1;
	  if (optind > argc)
	    usage();
	  g_dataset_file = argv[optind++];
	  if (optind > argc)
	    usage();
	  g_correspondence_file = argv[optind++];
	  if (optind > argc)
	    usage();
	  nline = atoi(argv[optind++]);
	  break;
	case opt_activate:
	  g_activate = 1;
	case opt_test:
	  g_test = 1;
	  if (optind > argc)
	    usage();
	  g_ocr_file = argv[optind++];
	  if (optind > argc)
	    usage();
	  g_dataset_file = argv[optind++];
	  if (optind > argc)
	    usage();
	  g_correspondence_file = argv[optind++];
	  if (optind > argc)
	    usage();
	  first_line = atoi(argv[optind++]);
	  if (optind > argc)
	    usage();
	  last_line = atoi(argv[optind++]);
	  break;
	case opt_output:
	  g_output = 1;
	  if (optind > argc)
	    usage();
	  g_ocr_file = argv[optind++];
	  break;
	}
    }

  NN<double> *nn = NULL;
  std::cout << g_train << std::endl;
  if (g_train)
    {
      std::cout << "train" << std::endl;
      std::vector<unsigned> nneurons;
      nneurons.push_back(16);
      nneurons.push_back(75);
      nneurons.push_back(26);
      
      tf_activation	fs[3];
      fs[0] = id;
      fs[1] = sigmoide2;
      fs[2] = sigmoide;

      nn = new NN<double>(3, nneurons, fs, 0.0);
      /*Pswarm<double, char> pswarm(g_correspondence_file, 
				  new Letter_recognition<double, char>
				  (g_dataset_file), nn, nline, 0.1, 500, 
				  -500.0, 500.0);
				  pswarm.learn();*/

      Backprop<double, char> backprop(g_correspondence_file, 
				      new Letter_recognition<double, char>
				      (g_dataset_file), 
				      nn, nline, 0.001, 0.2);		      
      backprop.learn();
    }
  
  if (g_test)
    {
      std::cout << "test" << std::endl;
      nn = new NN<double>();
      nn->read(g_ocr_file);
      TestNN<double, char> *testnn = 
	new TestNN<double, char>(g_correspondence_file,
				 new Letter_recognition<double, char>
				 (g_dataset_file), 
				 nn, first_line, last_line);
      testnn->test();
    }
  
  if (nn && g_output)
    nn->write(g_ocr_file);

  return 0;
}
