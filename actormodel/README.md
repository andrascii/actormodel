# ActorModel

Project to demonstrate actor model pattern based on Qt event queues.

## It contains the sample application terminal/console based that:
1. registrates HTTP downloader handler
2. sends request to this HTTP downloader handler
3. receives response from HTTP downloader handler

## Base features are:
- requesters and handlers may work in different threads
- handler delivers response to the requester and calls its callback in the thread in which requester is lives
