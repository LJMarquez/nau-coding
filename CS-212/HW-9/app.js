console.log("Hello World!");

let downloadResumeButton = document.getElementById("download-resume-btn");
let nameHeader = document.getElementById("name-header");
let deadlineDateElement = document.getElementById("stock-trader-deadline-date");
let deadlineDaysLeftElement = document.getElementById("stock-trader-deadline-days-left");
let projectsContainer = document.getElementById("projects-container");
let resumeDownloadCountElement = document.getElementById("resume-download-count");
let skillInput = document.getElementById("new-skill-input");

const name = "Leo";
let resumeDownloadCount = 0;

let hasDownloadedResume = false;

downloadResumeButton.addEventListener("click", function () {
    if (!hasDownloadedResume) {
        hasDownloadedResume = true;
        setTimeout(function () {
            alert("Your resume is downloaded successfully!");
        }, 2000);
    }
});

function showGreeting(name) {
    let currentDate = new Date();
    let currentHour = currentDate.getHours();
    let greeting;
    if (currentHour > 4 && currentHour < 13) {
        greeting = "Good Morning";
    }
    else if (currentHour > 12 && currentHour < 18) {
        greeting = "Good Afternoon";
    }
    else {
        greeting = "Good Evening";
    }
    nameHeader.innerHTML = greeting + ", my name is " + name + "! Welcome to my portfolio!";
}

document.addEventListener("DOMContentLoaded", function () {
    showGreeting(name);
});

function daysUntilDeadline(deadline) {
    let currentDate = new Date();
    let deadlineDate = new Date(deadline);
    let timeDifference = deadlineDate - currentDate;
    let daysDifference = timeDifference / (1000 * 3600 * 24);
    return Math.round(daysDifference);
}

function addResumeDownloadCount() {
    resumeDownloadCount++;
    resumeDownloadCountElement.innerText = resumeDownloadCount;
}

let educationTableContainer = document.getElementById("education-table-container");
let experienceTableContainer = document.getElementById("experience-table-container");

let educationTableHeaders = ["School Name", "Degree", "Graduation Year"];
let educationTableData = [
    ["Northern Arizona University", "B.A. in Computer Science, Minor in Cybersecurity", "2029"],
    ["West-MEC Central Campus", "Certificate in Application Development & JavaScript", "2025"]
];

let experienceTableHeaders = ["Organization", "Position", "Duration"];
let experienceTableData = [
    ["NAU Information Technology Services", "Information Security Services Student Employee", "2025 - Present"],
    ["Agua Fria High School District", "Graphic Design Intern", "2024 - 2025"]
];

let educationTable = document.createElement("table");
educationTable.classList.add("table", "table-striped", "table-hover", "align-middle");
let educationTableHead = document.createElement("thead");
educationTableHead.classList.add("table-dark");
let educationHeaderRow = document.createElement("tr");
for (let i = 0; i < educationTableHeaders.length; i++) {
    let header = document.createElement("th");
    header.innerText = educationTableHeaders[i];
    educationHeaderRow.appendChild(header);
}
educationTableHead.appendChild(educationHeaderRow);
educationTable.appendChild(educationTableHead);

let educationTableBody = document.createElement("tbody");

for (let i = 0; i < educationTableData.length; i++) {
    let row = document.createElement("tr");
    for (let j = 0; j < educationTableData[i].length; j++) {
        let cell = document.createElement("td");
        cell.innerText = educationTableData[i][j];
        row.appendChild(cell);
    }
    educationTableBody.appendChild(row);
}

educationTable.appendChild(educationTableBody);
educationTableContainer.appendChild(educationTable);



let experienceTable = document.createElement("table");
experienceTable.classList.add("table", "table-striped", "table-hover", "align-middle");
let experienceTableHead = document.createElement("thead");
experienceTableHead.classList.add("table-dark");
let experienceHeaderRow = document.createElement("tr");
for (let i = 0; i < experienceTableHeaders.length; i++) {
    let header = document.createElement("th");
    header.innerText = experienceTableHeaders[i];
    experienceHeaderRow.appendChild(header);
}
experienceTableHead.appendChild(experienceHeaderRow);
experienceTable.appendChild(experienceTableHead);

let experienceTableBody = document.createElement("tbody");

for (let i = 0; i < experienceTableData.length; i++) {
    let row = document.createElement("tr");
    for (let j = 0; j < experienceTableData[i].length; j++) {
        let cell = document.createElement("td");
        cell.innerText = experienceTableData[i][j];
        row.appendChild(cell);
    }
    experienceTableBody.appendChild(row);
}

experienceTable.appendChild(experienceTableBody);
experienceTableContainer.appendChild(experienceTable);


// jQuery

let otherSkillsList = [];

$("#add-skill-form").on("submit", function (e) {
    e.preventDefault();
    let skill = $("#new-skill-input").val();
    
    if (otherSkillsList.includes(skill)) {
        alert("That skill already exists.");
    }
    else {
        otherSkillsList.push(skill);
        
        if (otherSkillsList.length === 1) {
            $("#other-skills-list").empty();
        }
        
        let $newSkillItem = $("<li>", {
            class: "list-group-item d-flex justify-content-between align-items-center",
            "data-skill": skill,
            css: { display: "none" }
        });
        
        let $skillInput = $("<input>", {
            type: "text",
            class: "border-0 bg-transparent text-dark",
            value: skill,
            disabled: true
        });
        
        let $editBtn = $("<button>", {
            type: "button",
            class: "btn btn-secondary mx-1",
            text: "Edit"
        });
        
        let $saveBtn = $("<button>", {
            type: "button",
            class: "btn btn-success mx-1 d-none",
            text: "Save"
        });
        
        let $removeBtn = $("<button>", {
            type: "button",
            class: "btn btn-danger mx-1",
            text: "Remove"
        });
        
        let $btnWrapper = $("<span>").append($editBtn, $saveBtn, $removeBtn);
        
        $newSkillItem.append($skillInput, $btnWrapper);
        $("#other-skills-list").append($newSkillItem);
        
        $newSkillItem.slideDown(250).fadeIn(250);
        
        $("#new-skill-input").val("");
        
        // Edit button handler
        $editBtn.on("click", function () {
            $skillInput.prop("disabled", false).removeClass("border-0").addClass("border border-dark").focus();
            $saveBtn.removeClass("d-none").fadeIn(150);
            $editBtn.addClass("d-none");
        });
        
        // Save button handler
        $saveBtn.on("click", function () {
            let newSkill = $skillInput.val().trim();
            if (!newSkill) return;
            
            if (newSkill !== skill && otherSkillsList.includes(newSkill)) {
                alert("That skill already exists.");
                return;
            }
            
            let currentSkillIndex = otherSkillsList.indexOf(skill);
            if (currentSkillIndex !== -1) {
                otherSkillsList[currentSkillIndex] = newSkill;
            }
            
            $newSkillItem.attr("data-skill", newSkill);
            skill = newSkill;
            
            $skillInput.prop("disabled", true).addClass("border-0").removeClass("border border-dark");
            $saveBtn.addClass("d-none");
            $editBtn.removeClass("d-none").fadeIn(150);
        });
        
        // Remove button handler with animation
        $removeBtn.on("click", function () {
            let skillToRemove = $newSkillItem.attr("data-skill");
            let currentSkillIndex = otherSkillsList.indexOf(skillToRemove);
            if (currentSkillIndex !== -1) {
                otherSkillsList.splice(currentSkillIndex, 1);
            }
            
            $newSkillItem.slideUp(250, function () {
                $(this).remove();
            });
        });
    }
});

// Escape key to clear skill input
$(document).on("keydown", function (e) {
    if (e.key === "Escape") {
        $("#new-skill-input").val("");
    }
});

// jQuery implementation for projects with sorting functionality

let projects = [
    {
        title: "Edumon",
        image: "edumon.png",
        description: "A full-stack turn-based RPG built with React Native where players collect and battle monsters by answering educational questions.",
        deadline: "2024-08-19"
    },
    {
        title: "Culinary Showdown",
        image: "culinary-showdown.png",
        description: "A typing/adventure game built using HTML, CSS, and JavaScript with audio and interactivity.",
        deadline: "2023-11-08"
    },
    {
        title: "Stock Trader",
        image: "stock-trading.jpeg",
        description: "Work in progress.",
        deadline: "2028-05-13"
    }
];

let sortOrder = "asc";

function renderProjects(projectsArray) {
    $("#projects-container").empty();
    
    for (let i = 0; i < projectsArray.length; i++) {
        let project = projectsArray[i];
        let currentDate = new Date();
        let deadlineDate = new Date(project.deadline);
        let currentState;
        let stateColor;
        
        if (currentDate > deadlineDate) {
            currentState = "Completed";
            stateColor = "green";
        } else {
            currentState = "Ongoing";
            stateColor = "red";
        }
        
        let $projectCard = $(`
            <div>
                <div class="card h-100 shadow-sm">
                    <img src="${project.image}" class="card-img-top" alt="${project.title}">
                    <div class="card-body">
                        <h3 class="h5 card-title">${project.title}</h3>
                        <p class="card-text mb-0">${project.description}</p>
                        <p class="card-text mb-0">Deadline: ${project.deadline}</p>
                        <p class="card-text mb-0" style="color: ${stateColor};">Current state: ${currentState}</p>
                    </div>
                </div>
            </div>
        `);
        
        // Use jQuery animations for adding projects
        $projectCard.hide().fadeIn(500);
        $("#projects-container").append($projectCard);
    }
}

function sortProjectsByDeadline(ascending) {
    projects.sort(function (a, b) {
        let dateA = new Date(a.deadline).getTime();
        let dateB = new Date(b.deadline).getTime();
        if (ascending) {
            return dateA - dateB;
        } else {
            return dateB - dateA;
        }
    });
    
    renderProjects(projects);
    
    // Update button text to show current direction
    let buttonText;
    if (ascending) {
        buttonText = "Sort: Latest First";
    } else {
        buttonText = "Sort: Earliest First";
    }
    $("#sort-projects-btn").text(buttonText);
}

// Initial render
renderProjects(projects);

// Add sort button to Projects section header (if it doesn't exist)
$("#projects-container").parents(".container").find(".row").first().append(`
    <div class="col-12 text-center mb-3">
        <button id="sort-projects-btn" class="btn btn-outline-dark">Sort: Latest First</button>
    </div>
`);

// Sort button click handler
$(document).on("click", "#sort-projects-btn", function () {
    if (sortOrder === "asc") {
        sortOrder = "desc";
    } else {
        sortOrder = "asc";
    }
    
    let isAscending;
    if (sortOrder === "asc") {
        isAscending = true;
    } else {
        isAscending = false;
    }
    sortProjectsByDeadline(isAscending);
});