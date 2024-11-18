#include <stdio.h>
#include "xmlparse.h"

int xml_parsercreate__(int *input)
{
  XML_Parser parser;
  parser = XML_ParserCreate(NULL);
  return((int)parser);
}
int xml_parserfree__(int *parser)
{
  XML_ParserFree((XML_Parser)*parser);
  return(0);
}
void xml_setuserdata__(int *parser, int *idepth)
{
  XML_SetUserData((XML_Parser)*parser,idepth);
  return;
}
void startElement(void *userData, const char *name, const char **atts)
{
  int i;
  int *depthPtr = userData;
  for (i = 0; i < *depthPtr; i++)
    putchar('\t');
  puts(name);
  *depthPtr += 1;
}
void endElement(void *userData, const char *name)
{
  int *depthPtr = userData;
  *depthPtr -= 1;
}
void xml_setelementhandler__(int *parser)
{
  XML_SetElementHandler((XML_Parser)*parser, startElement, endElement);
  return;
}
/*
 * add ed for debugging
 */
void xml_parserprinter__(int *parser)
{
  printf("parser=%d\n",*parser);
  fflush(stdout);
  return;
}
void xml_parserreader__(int *parser)
{
  int done;
  char buf[2048]; /* BUFSIZE */
  do {
    size_t len = fread(buf, 1, sizeof(buf), stdin);
    done = len < sizeof(buf);
    if (!XML_Parse((XML_Parser)*parser, buf, len, done)) {
      fprintf(stderr,
	      "%s at line %d\n",
	      XML_ErrorString(XML_GetErrorCode(parser)),
	      XML_GetCurrentLineNumber(parser));
      return;
    }
  } while (!done);
}

int startelement_(muserData,name,matts)
int *muserData;
char *name;
int **matts;
{
startElement(muserData,name,matts);
}

int endelement_(muserData,name)
int *muserData;
char *name;
{
endElement(muserData,name);
}
