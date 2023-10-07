// Function to get the current time in a user-friendly format
function getCurrentTime() {
  const now = new Date();
  const hours = now.getHours();
  const minutes = now.getMinutes();
  const amOrPm = hours >= 12 ? 'PM' : 'AM';

  // Convert hours to 12-hour format
  const formattedHours = hours % 12 || 12;

  // Add leading zero to minutes if less than 10
  const formattedMinutes = minutes < 10 ? '0' + minutes : minutes;

  return `${formattedHours}:${formattedMinutes} ${amOrPm}`;
}

// Prompt the user for their name
const userName = prompt("Enter your name:");

// Get the current time
const currentTime = getCurrentTime();

// Create a greeting message
const greeting = `Hi ${userName}, welcome! I hope you're doing well. The current time is ${currentTime}.`;

// Display the greeting message
console.log(greeting);
