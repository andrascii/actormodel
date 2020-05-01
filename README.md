# ActorModel

Project to demonstrate actor model pattern based on Qt event queues.

## It contains the sample application terminal/console based that:
1. registrates math operation handler that can perform simple operations: plus/minus/multiply/divide
2. sends request to this handler
3. receives response from that and print it in a widget

## Base features are:
- requesters and handlers may work in different threads
- handler delivers response to the requester and calls its callback in the thread in which requester is lives
