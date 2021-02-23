
#include "DataChunk.h"
#include "DataManager.h"

namespace Data {

DataChunk::DataChunk(const I8u & _numBytes, DataChunk * const & _nextPtr)
	:numBytes(_numBytes)
	,nextPtr(_nextPtr)
	,locked(false)
{
	dat