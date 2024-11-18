      program callingC
c
c *** Fortran.c functions
c
      integer XML_ParserCreate
      external XML_ParserCreate
      external XML_ParserFree
      external XML_SetElementHandler
c debugging
c     external XML_ParserPrinter
c
c *** calling.c functions
c
      external startElement
      external endElement
c
c *** Expat parameters
c
c
c *** Local parameters
c
      integer iparser
      integer iret
      integer ixml
      integer idepth
c
c *** Initialization
c
c     should be NULL not zero
      ixml=0
      idepth=0
      iparser=XML_ParserCreate(ixml)
c
c debugging
      call XML_ParserPrinter(iparser)
c
      call XML_SetUserData(iparser, idepth)
      call XML_SetElementHandler(iparser)
      call XML_ParserReader(iparser)
c
      call XML_ParserFree(iparser)
c
      end
