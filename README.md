# Coffee machine
## Goal

Describe the basic architecture of a coffee vending machine.

## Interfaces

```pseudo
interface User {
  selectDrink()
  insertPayment()
  collectDrink()
}

interface Machine {
  displayMenu()
  validatePayment()
  checkAvailability()
  prepareDrink()
  showMessage()
}
```

## Use Cases

- User selects a drink
- User inserts payment
- Machine validates the selection
- Machine prepares the drink
- User collects the drink

## Possible Errors

- Payment failed
- Drink unavailable
- Technical issue (e.g. heating error, motor jam)
- Drink not collected by user

## Full Scenario (with errors)
```pseudo
User arrives
Machine.displayMenu()

User.selectDrink()
Machine.showMessage("Please insert payment")

User.insertPayment()

if Machine.validatePayment() == false:
    Machine.showMessage("Payment failed")
    stop

if Machine.checkAvailability() == false:
    Machine.showMessage("Drink unavailable")
    refundPayment()
    stop

try:
    Machine.prepareDrink()
except TechnicalIssue:
    Machine.showMessage("Technical error. Please try later.")
    refundPayment()
    stop

Machine.showMessage("Please collect your drink")
User.collectDrink()

if drinkStillInside():
    Machine.showMessage("Drink not collected")
    notifyMaintenance()

```
## Notes
- The user interacts via screen or buttons
- The machine responds step-by-step in a predictable way
