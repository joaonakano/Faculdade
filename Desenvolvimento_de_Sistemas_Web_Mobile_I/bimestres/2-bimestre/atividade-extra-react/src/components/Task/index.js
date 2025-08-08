

export default function Task({ title, completed }) {

    return (
        <>
            {completed? (
                <li>{title} - ✅</li>
            ) : (
                <li>{title}</li>
            )}
        </>
    );
}

// If completed, then completed + title
// If not completed, then title
// Completed = true/false
// If true